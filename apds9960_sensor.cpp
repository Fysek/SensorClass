#include "sensor.h"


class BME680: public Sensor {       
  private:
  
  public:             
	virtual void configure();
	int getSensorID(); 
	
    
    
    
};
