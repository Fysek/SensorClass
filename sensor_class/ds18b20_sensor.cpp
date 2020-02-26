#include "ds18b20_sensor.h"

void DS18B20::configure(){
    std::cout << "Configure your DS18B20 sensor here..."<<std::endl;
}

void DS18B20::startConnection(){
    std::cout << "Configure start connection of your DS18B20 sensor here..."<<std::endl;
}

void DS18B20::stopConnection(){
    std::cout << "Configure stop connection of your DS18B20 sensor here..."<<std::endl;
}

void DS18B20::measure(int delayTime, int nMeas, Data &outputData, char *outputFile){
   //nothing
}

void DS18B20::I2CSetAddress(int address){
	//nothing
}