#include "data.h"
#include <iostream>

#ifndef SENSOR_H
#define SENSOR_H


class Sensor {
  private:
	int 	    _id;
    static int  counter;

  public:
	Sensor();
	~Sensor();
	virtual void configure() = 0;
	int getSensorID();

};


#endif
