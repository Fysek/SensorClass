#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include "sensor.h"

class DHT11: public Sensor {
  public:
	void configure() override;
	void measure(int delay, int nMeas, Data &outputData, char *outputFile) override;
	void startConnection() override;
	void stopConnection() override;
	void I2CSetAddress(int address) override; 

};

#endif
