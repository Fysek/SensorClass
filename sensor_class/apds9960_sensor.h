#ifndef APDS9960_SENSOR_H
#define APDS9960_SENSOR_H

#include "sensor.h"

class APDS9960: public Sensor {
  public:
	void configure() override;
	void startConnection() override;
	void stopConnection() override;

};

#endif
