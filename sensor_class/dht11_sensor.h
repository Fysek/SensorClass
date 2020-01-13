#include "sensor.h"

#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

class DHT11: public Sensor {
  public:
	void configure();
	void startConnection();
	void stopConnection();

};

#endif
