#include "../sensor.h"

class BME680: public Sensor {
  public:
	BME680();
	void configure();
	void measure() ;
	void startConnection();
	void stopConnection();
	void I2CSetAddress(); 
};

class APDS9960: public Sensor {
  public:
	APDS9960();
	void configure();
	void measure() ;
	void startConnection();
	void stopConnection();
	void I2CSetAddress(); 
};

class DHT11: public Sensor {
  public:
	DHT11();
	void configure();
	void measure() ;
	void startConnection();
	void stopConnection();
	void I2CSetAddress(); 

};

class DS18B20: public Sensor {
  public:
	DS18B20();
	void configure();
	void measure() ;
	void startConnection();
	void stopConnection();
	void I2CSetAddress(); 
};

