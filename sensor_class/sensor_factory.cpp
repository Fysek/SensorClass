#include "sensor_factory.h"

Sensor* SensorFactory::CreateSensor(SensorType type) { 
    if (type == ST_DHT11) 
        return new DHT11(); 
    else if (type == ST_APDS9960) 
        return new APDS9960(); 
    else if (type == ST_BME680) 
        return new BME680(); 
	else if (type == ST_DS18B20) 
        return new DS18B20(); 
    else return NULL; 
} 