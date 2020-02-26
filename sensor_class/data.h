#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>

class Data{
	private:
		float 	m_temperature;
		float 	m_humidity;
		float 	m_pressure;
		float 	m_gasResistance;
		float 	m_proximity;
		int 	m_smokeLevel;
		int 	m_distance;
	

	public:
		Data();
		Data(
			float 	temperature, 
			float 	humidity, 
			float 	pressure, 
			float 	gasResistance, 
			float 	proximity, 
			int 	smokeLevel, 
			int 	distance
			);
		
		void printData();
		std::string toString();
   
		void setTemperature(float temperature);
		void setHumidity(float humidity);
		void setPressure(float pressure);
		void setGasResistance(float gasResistance);
		void setProximity(float proximity);
		void setSmokeLevel(int smokeLevel);
		void setDistance(int distance);

		float getTemperature();
		float getHumidity();
		float getPressure();
		float getGasResistance();
		float getProximity();
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
