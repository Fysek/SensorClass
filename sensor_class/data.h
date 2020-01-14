#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>

class Data{
	private:
		float 				_temperature;
		float 				_humidity;
		float 				_pressure;
		int 				_gasResistance;
		int 				_proximity;
		int 				_smokeLevel;
		int 				_distance;
	

	public:
		Data();
		Data(float, float, float, int, int, int, int);
		void printData();
    std::string toString();
   
		void setTemperature(float temperature);
		void setHumidity(float humidity);
		void setPressure(float pressure);
		void setGasResistance(int gasResistance);
		void setProximity(int proximity);
		void setSmokeLevel(int smokeLevel);
		void setDistance(int distance);

		float getTemperature();
		float getHumidity();
		float getPressure();
		int getGasResistance();
		int getProximity();
		int getSmokeLevel();
		int getDistance();

		
		
};

#endif
