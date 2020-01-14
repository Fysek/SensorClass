#include <iostream>
#include <cstdlib>
#include <string>
//#include <thread>	
#include <atomic>
#include <chrono>
#include <cstring>

#include "../sensor_class/sensor.h"
#include "../sensor_class/bme680_sensor.h"
#include "../sensor_class/apds9960_sensor.h"
#include "../sensor_class/dht11_sensor.h"
#include "../sensor_class/ds18b20_sensor.h"
#include "../mqtt/callback.h"
#include "../../../paho.mqtt.cpp/src/mqtt/async_client.h"

const int BME680_I2C_ADDR = 0x76;

const std::string ADDRESS	    { "192.168.12.193" };
const std::string CLIENT_ID		{ "Raspberry Pi 1" };
const std::string TOPIC { "BME680" };
const char* LWT_PAYLOAD = "End of transmission";
const int  QOS = 1;
const auto TIMEOUT = std::chrono::seconds(10);



int main(){

  /*Hardware site*/
  BME680 iBME680(BME680_I2C_ADDR);
  APDS9960 iAPDS9960;
  DHT11 iDHT11;
  DS18B20 iDS18B20;
  Data dataBME680;
  char *outputFile = "log.txt";
  int i=0;
  std::string payload;
  //////////////////////////////////  
    
  /*MQTT config*/ 
  std::cout << "Initializing for server '" << ADDRESS << "'..." << std::endl;
  mqtt::async_client client(ADDRESS, CLIENT_ID);

	callback cb;
	client.set_callback(cb);

	mqtt::connect_options conopts;
	mqtt::message willmsg(TOPIC, LWT_PAYLOAD, 1, true);
	mqtt::will_options will(willmsg);
	conopts.set_will(will);
  //////////////////////////////////    
    
    
  /*MQTT connect*/   
 	try {
		std::cout << "\nConnecting..." << std::endl;
		mqtt::token_ptr conntok = client.connect(conopts);
		std::cout << "Waiting for the connection..." << std::endl;
		conntok->wait();
		std::cout << "  ...OK" << std::endl; 
  ////////////////////////////////// 
      
  /*BME680 connect*/  
    iBME680.startConnection();
    iBME680.configure();
  //////////////////////////////////   

    while(1){
      iBME680.measure(5, 1, dataBME680, outputFile);
      payload = dataBME680.toString();
      std::cout << "\nSending message..." << std::endl;
		  mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload);
		  pubmsg->set_qos(QOS);
		  client.publish(pubmsg)->wait_for(TIMEOUT);
      //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    } 
     
    /*BME680 disconnect*/   
    iBME680.stopConnection();
  ////////////////////////////////// 
    
    /*MQTT disconnect*/
    std::cout << "\nDisconnecting..." << std::endl;
		conntok = client.disconnect();
		conntok->wait();
		std::cout << "  ...OK" << std::endl;
  //////////////////////////////////
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	} 
  return 0;
}
