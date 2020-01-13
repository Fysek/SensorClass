#include "sensor.h"

#ifndef DS18B20_SENSOR_H
#define DS18B20_SENSOR_H

class DS18B20: public Sensor {
  public:
	void configure();
	void startConnection();
	void stopConnection();

};

#endif
