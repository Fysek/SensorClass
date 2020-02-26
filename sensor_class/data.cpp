#include <iostream>
#include "data.h"


Data::Data(){
    m_temperature     =	0;
    m_humidity        =	0;
    m_pressure        =	0;
    m_gasResistance   =	0;
    m_proximity       =	0;
    m_smokeLevel      =	0;
    m_distance        =	0;
}

Data::Data(
			float 	temperature,
			float 	humidity,
			float 	pressure,
			float 	gasResistance,
			float 	proximity,
			int 	smokeLevel,
			int 	distance
			)
			{
				m_temperature     = temperature;
				m_humidity        = humidity;
				m_pressure        = pressure;
				m_gasResistance   = gasResistance;
				m_proximity       = proximity;
				m_smokeLevel      = smokeLevel;
				m_distance        = distance;
			}

void Data::printData(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
    
    std::cout <<  tm.tm_year + 1900 << "/" 
                << std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << "/" 
                << std::setfill('0') << std::setw(2) << tm.tm_mday << " " 
                << std::setfill('0') << std::setw(2) << tm.tm_hour << ":" 
                << std::setfill('0') << std::setw(2) << tm.tm_min << ":"
                << std::setfill('0') << std::setw(2) << tm.tm_sec;

    std::cout << " Temperature: "<< m_temperature <<" degC"
              << ", Humidity: "<< m_humidity <<" %rH"
              << ", Pressure: "<< m_pressure <<" hPa"
              << ", Gas resistance: "<< m_gasResistance <<" kOhms"
              << ", Proximity: "<< m_proximity <<" %"
              << ", Smoke level: "<< m_smokeLevel <<" %"
              << ", Distance: "<< m_distance <<" m"<<std::endl;
}

std::string Data::toString(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	std::stringstream ss;
	ss << tm.tm_year + 1900 << "/" 
        << std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << "/" 
        << std::setfill('0') << std::setw(2) << tm.tm_mday << " "  
        << std::setfill('0') << std::setw(2) << tm.tm_hour << ":" 
        << std::setfill('0') << std::setw(2) << tm.tm_min << ":"  
        << std::setfill('0') << std::setw(2) << tm.tm_sec
        << " Temperature: "<< m_temperature <<" °C"
        << ", Humidity: "<< m_humidity <<" %rH"
        << ", Pressure: "<< m_pressure <<" hPa"
        << ", Gas resistance: "<< m_gasResistance <<" kOhms"
        << ", Proximity: "<< m_proximity <<" %"
        << ", Smoke level: "<< m_smokeLevel <<" %"
        << ", Distance: "<< m_distance <<" m";
                        
  return ss.str();
}

void Data::setTemperature(float temperature)	{ m_temperature = temperature; }
void Data::setHumidity(float humidity)			{ m_humidity = humidity; }
void Data::setPressure(float pressure)			{ m_pressure = pressure; }
void Data::setGasResistance(float gasResistance){ m_gasResistance = gasResistance; }
void Data::setProximity(float proximity)		{ m_proximity = proximity; }
void Data::setSmokeLevel(int smokeLevel)		{ m_smokeLevel = smokeLevel; }
void Data::setDistance(int distance)			{ m_distance = distance; }

float Data::getTemperature()					{ return m_temperature; }
float Data::getHumidity()						{ return m_humidity; }
float Data::getPressure()						{ return m_pressure; }
float Data::getGasResistance()					{ return m_gasResistance; }
float Data::getProximity()						{ return m_proximity; }
int Data::getSmokeLevel()						{ return m_smokeLevel; }
int Data::getDistance()							{ return m_distance; }

std::string Data::toStringTemperature(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_temperature;
	return ss.str();
}

std::string Data::toStringHumidity(){ 	
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_humidity;
	return ss.str();
}

std::string Data::toStringPressure(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_pressure;
	return ss.str();
}

std::string Data::toStringGasResistance(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_gasResistance;
	return ss.str();
}

std::string Data::toStringProximity(){ 
 	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_proximity;
	return ss.str();
}

std::string Data::toStringSmokeLevel(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_smokeLevel;
	return ss.str();
}

std::string Data::toStringDistance(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << m_distance;
	return ss.str();
}



