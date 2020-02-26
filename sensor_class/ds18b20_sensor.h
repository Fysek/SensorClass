#ifndef DS18B20_SENSOR_H
#define DS18B20_SENSOR_H

#include "sensor.h"


class DS18B20: public Sensor {
  public:
	void configure() override;
	void measure(int delayTime, int nMeas, Data &outputData, char *outputFile) override;
	void startConnection() override;
	void stopConnection() override;
	void I2CSetAddress(int address) override; 

};

#endif
