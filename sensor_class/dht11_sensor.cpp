#include "dht11_sensor.h"

void DHT11::configure(){
    std::cout << "Configure your DHT11 sensor here..."<<std::endl;
}

void DHT11::startConnection(){
    std::cout << "Configure start connection of your DHT11 sensor here..."<<std::endl;
}

void DHT11::stopConnection(){
    std::cout << "Configure stop connection of your DHT11 sensor here..."<<std::endl;
}

void DHT11::measure(int delay, int nMeas, Data &outputData, char *outputFile){
   //nothing
}

void DHT11::I2CSetAddress(int address){
	//nothing
}