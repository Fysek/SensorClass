


#include "apds9960_sensor.h"

int APDS9960_I2CAddress;

APDS9960::APDS9960(){
	APDSObj = new APDS9960_RPi();
}

APDS9960::~APDS9960(){
	delete APDSObj;
}

float APDS9960::calculateProximityPrc(int proximity){
	float result;
	
	if((proximity >= 0)&&(proximity < 15))
	{
		result = 0.0;
	} 
	else if((proximity >= 15)&&(proximity < 30))
	{
		result = float(proximity)*0.66 - 10.0;	
	} 
	else if((proximity >= 30)&&(proximity < 50))
	{
		result = float(proximity)*1.1 - 23.0;	
	} 
	else if((proximity >= 50)&&(proximity < 105))
	{
		result = float(proximity)*0.327 + 15.63;
	} 
	else if((proximity >= 105)&&(proximity < 220))
	{
		result = float(proximity)*0.43 + 4.35;
	} 
	else if((proximity >= 220)&&(proximity <= 255))
	{
		result = 100.0;
	} 
	else 
	{ 
		result = 0.0;
	}
	
	return result;	
}

void APDS9960::configure(){
	if ( APDSObj->init() ) {
		std::cout << "APDS-9960 initialization complete" << std::endl;
	} else {
		std::cout << "Something went wrong during APDS-9960 init!" << std::endl;
	}

	if (!(APDSObj->setProximityGain(PGAIN_2X))) {
		std::cout << "Something went wrong trying to set PGAIN" << std::endl;
	}

	if ( APDSObj->enableProximitySensor(false) ) {
		std::cout << "Proximity sensor is now running" << std::endl;
	} else {
		std::cout << "Something went wrong during sensor init!" << std::endl;
	}
}

void APDS9960::startConnection(){
    if (APDSObj->connect(APDS9960_I2CAddress)) {
		std::cout << "APDS-9960 connected" << std::endl;
	} else {
		std::cout << "Something went wrong during APDS-9960 connect!" << std::endl;
	}
}

void APDS9960::stopConnection(){
	
}

void APDS9960::measure(int delayTime, int nMeas, Data &outputData, char *outputFile){
   	int i=0;
	uint8_t proximity_data;
	float calcdata;
	while(i<nMeas) {
		if ( !APDSObj->readProximity(proximity_data) ) {
			std::cout << "Error reading proximity value" << std::endl;
		}
			//std::cout << "Proximity: ";
			//std::cout << int(proximity_data) << std::endl;
		calcdata = calculateProximityPrc(int(proximity_data));
		outputData.setProximity(int(calcdata));
		delay(delayTime*1000);
		i++;
	}
}


void APDS9960::I2CSetAddress(int address){
	APDS9960_I2CAddress = address;
}