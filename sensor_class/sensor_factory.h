#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include "sensor.h"
#include "bme680_sensor.h"
#include "apds9960_sensor.h"
#include "dht11_sensor.h"
#include "ds18b20_sensor.h"


enum SensorType { 
    ST_DHT11, ST_APDS9960, ST_BME680,  ST_DS18B20 
}; 

class SensorFactory {
  public:
	Sensor* CreateSensor(SensorType type); 
	void DestroySensor(Sensor* sensor); 
};


#endif


