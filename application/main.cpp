#include <iostream>
#include <cstdlib>
#include <string>
#include <atomic>
#include <chrono>
#include <cstring>
#include <math.h>

#include "../sensor_class/sensor.h"
#include "../sensor_class/sensor_factory.h"
#include "../sensor_class/bme680_sensor.h"
#include "../sensor_class/apds9960_sensor.h"
#include "../sensor_class/dht11_sensor.h"
#include "../sensor_class/ds18b20_sensor.h"
#include "../mqtt/callback.h"
#include "../../../paho.mqtt.cpp/src/mqtt/async_client.h"

const int BME680_I2C_ADDR = 0x76;


const std::string ADDRESS	    { "192.168.12.193" };
const std::string CLIENT_ID		{ "Raspberry Pi 1" };
const char* LWT_PAYLOAD 		= "Transmission";
const int  QOS 					= 1;
const int  NUMBER_OF_TOPICS		= 5;
const auto TIMEOUT 				= std::chrono::seconds(10);

std::string timeConv(struct tm time){
	std::stringstream ss;
	ss << time.tm_year + 1900 << "/" << 
		std::setfill('0') << std::setw(2) << time.tm_mon + 1 << "/" <<
        std::setfill('0') << std::setw(2) << time.tm_mday << " " << 
		std::setfill('0') << std::setw(2) << time.tm_hour << ":" << 
        std::setfill('0') << std::setw(2) << time.tm_min << ":" << 
        std::setfill('0') << std::setw(2) << time.tm_sec;                   
	return ss.str();
}

int main(){
	/*Hardware site*/
	
	SensorFactory *sensorFactory;
	Sensor *sensor_BME680;

	sensor_BME680 = sensorFactory->CreateSensor(ST_BME680);

	
	Data dataBME680;
	char *outputFile = "logs.log";
	std::string payload[NUMBER_OF_TOPICS];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	std::string TOPIC[NUMBER_OF_TOPICS]	;
    std::string messagsse	;
	/*MQTT config*/ 
	TOPIC[0]="home/datetime";
	TOPIC[1]="home/bme680/temperature";
	TOPIC[2]="home/bme680/humidity";
	TOPIC[3]="home/bme680/pressure";
	TOPIC[4]="home/bme680/gas_resistance";
	
	std::cout << "Initializing for server '" << ADDRESS << "'..." << std::endl;
	mqtt::async_client client(ADDRESS, CLIENT_ID);

	callback cb;
	client.set_callback(cb);
	
	mqtt::connect_options conopts;
	/*mqtt::message willmsg("Transmission", LWT_PAYLOAD, 1, true);
	mqtt::will_options will(willmsg);
	conopts.set_will(will);
   */
	/*MQTT connect*/   
 	try {
		std::cout << "\nConnecting..." << std::endl;
		mqtt::token_ptr conntok = client.connect(conopts);
		std::cout << "Waiting for the connection..." << std::endl;
		conntok->wait();
		std::cout << "  ...OK" << std::endl; 
		
		/*BME680 connect*/  
		sensor_BME680-> startConnection();
		sensor_BME680-> I2CSetAddress(BME680_I2C_ADDR);
		sensor_BME680-> configure();  

		while(1){
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			sensor_BME680->measure(5, 1, dataBME680, outputFile);
			payload[0] = timeConv(tm);
			payload[1] = dataBME680.toStringTemperature();
			payload[2] = dataBME680.toStringHumidity();
			payload[3] = dataBME680.toStringPressure();
			payload[4] = dataBME680.toStringGasResistance();
			
			for(int i=0; i<NUMBER_OF_TOPICS; i++){
				mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC[i], payload[i]);
				pubmsg->set_qos(QOS);
				client.publish(pubmsg)->wait_for(TIMEOUT);
			}	
		} 
     
		/*BME680 disconnect*/   
		sensor_BME680->stopConnection();
		
		/*MQTT disconnect*/
		std::cout << "\nDisconnecting..." << std::endl;
		conntok = client.disconnect();
		conntok->wait();
		std::cout << "  ...OK" << std::endl;

	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	}
	return 0;
}
