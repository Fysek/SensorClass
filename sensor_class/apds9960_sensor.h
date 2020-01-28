#ifndef APDS9960_SENSOR_H
#define APDS9960_SENSOR_H

#include "sensor.h"

class APDS9960: public Sensor {
  public:
	void configure() override;
	void measure(int delay, int nMeas, Data &outputData, char *outputFile) override;
	void startConnection() override;
	void stopConnection() override;
	void I2CSetAddress(int address) override; 

};

#endif
