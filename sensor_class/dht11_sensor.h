#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include "sensor.h"

class DHT11: public Sensor {
  public:
	void configure() override;
	void startConnection() override;
	void stopConnection() override;

};

#endif
