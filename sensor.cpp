#include "sensor.h"


class Sensor {       
  private:
	int 	_id;
	Data 	_sensorData;
  
  public:             
	virtual void configure();
	int getSensorID(); 
	void setSensorID(int id); 
	void setData(Data* data);	
    
    
    
};
