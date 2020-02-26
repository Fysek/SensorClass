#ifndef APDS9960_SENSOR_H
#define APDS9960_SENSOR_H

#include "sensor.h"
#include "../apds9960_controller/apds9960_rpi.h"

class APDS9960: public Sensor {
	private:
		APDS9960_RPi *APDSObj;
	public:
		APDS9960();
		~APDS9960();
		float calculateProximityPrc(int proximity);
		void configure() override;
		void measure(int delayTime, int nMeas, Data &outputData, char *outputFile) override;
		void startConnection() override;
		void stopConnection() override;
		void I2CSetAddress(int address) override; 
};

#endif
