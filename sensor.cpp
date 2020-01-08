#include "sensor.h"


class Sensor {       
  private:
    float 				temperature;
	float 				humidity;
	float 				pressure;
	int 				gasResistance;
	int 				proximity;
	int 				smokeLevel;
	int 				distance;
	std::vector<int>	auxData;
  
  public:             
	virtual void configure();
	int getSensorID(); 
	void setData(float, float, float, int, int, int, int, std::vector<int>);	
    
    
    
};
