#ifndef SENSOR_H
#define SENSOR_H

#include "data.h"
#include <iostream>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>



class Sensor {
  private:
	int 	    _id;
	static int  _counter;

  public:
	Sensor();
	~Sensor();
	int getSensorID();
	virtual void configure() = 0;
	virtual void measure(int delay, int nMeas, Data &outputData, char *outputFile) = 0;
	virtual void startConnection() = 0;
	virtual void stopConnection() = 0;
	virtual void I2CSetAddress(int address) = 0;
  
};


#endif
