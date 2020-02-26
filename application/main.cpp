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
const int APDS9960_I2C_ADDR = 0x39;

const std::string ADDRESS	    { "192.168.12.16" };
const std::string CLIENT_ID		{ "Raspberry Pi 1" };
const char* LWT_PAYLOAD 		= "Transmission";
const int  QOS 					= 1;
const int  NUMBER_OF_TOPICS		= 6;
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
	Sensor *sensorBME680;
	Sensor *sensorAPDS9960;
	
	sensorBME680 = sensorFactory->CreateSensor(ST_BME680);
	sensorAPDS9960 = sensorFactory->CreateSensor(ST_APDS9960);
	
	Data dataSensors;
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
	TOPIC[5]="home/bme680/proximity";
	
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
		//std::cout << "\nConnecting..." << std::endl;
		mqtt::token_ptr conntok = client.connect(conopts);
		//std::cout << "Waiting for the connection..." << std::endl;
		conntok->wait();
		//std::cout << "  ...OK" << std::endl; 
		
		/*BME680 connect*/  
		sensorBME680-> startConnection();
		sensorBME680-> I2CSetAddress(BME680_I2C_ADDR);
		sensorBME680-> configure();
		/*APDS9960 connect*/  
		sensorAPDS9960->I2CSetAddress(APDS9960_I2C_ADDR);
		sensorAPDS9960->startConnection();
		sensorAPDS9960->configure();
		
		while(1){
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			sensorBME680->measure(3, 1, dataSensors, outputFile);
			sensorAPDS9960->measure(2, 1, dataSensors, outputFile);
			payload[0] = timeConv(tm);
			payload[1] = dataSensors.toStringTemperature();
			payload[2] = dataSensors.toStringHumidity();
			payload[3] = dataSensors.toStringPressure();
			payload[4] = dataSensors.toStringGasResistance();
			payload[5] = dataSensors.toStringProximity();
			
			for(int i=0; i<NUMBER_OF_TOPICS; i++){
				mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC[i], payload[i]);
				pubmsg->set_qos(QOS);
				client.publish(pubmsg)->wait_for(TIMEOUT);
			}	
		} 
     
		/*BME680 disconnect*/   
		sensorBME680->stopConnection();
		sensorFactory->DestroySensor(sensorBME680);
		
		/*APDS9960 disconnect*/ 		
		sensorAPDS9960->stopConnection();
		sensorFactory->DestroySensor(sensorAPDS9960);
		
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
