#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>

class Data{
	private:
		float 	_temperature;
		float 	_humidity;
		float 	_pressure;
		float 	_gasResistance;
		int 	_proximity;
		int 	_smokeLevel;
		int 	_distance;
	

	public:
		Data();
		Data(float, float, float, float, int, int, int);
		void printData();
		std::string toString();
   
		void setTemperature(float temperature);
		void setHumidity(float humidity);
		void setPressure(float pressure);
		void setGasResistance(float gasResistance);
		void setProximity(int proximity);
		void setSmokeLevel(int smokeLevel);
		void setDistance(int distance);

		float getTemperature();
		float getHumidity();
		float getPressure();
		float getGasResistance();
		int getProximity();
		int getSmokeLevel();
		int getDistance();

		std::string toStringTemperature();
		std::string toStringHumidity(); 	
		std::string toStringPressure();
		std::string toStringGasResistance();
		std::string toStringProximity();
		std::string toStringSmokeLevel();
		std::string toStringDistance();
};

#endif
