#include <iostream>
#include "data.h"


Data::Data(){
    _temperature     =	0;
    _humidity        =	0;
    _pressure        =	0;
    _gasResistance   =	0;
    _proximity       =	0;
    _smokeLevel      =	0;
    _distance        =	0;
}

Data::Data(
			float 	temperature,
			float 	humidity,
			float 	pressure,
			float 	gasResistance,
			int 	proximity,
			int 	smokeLevel,
			int 	distance
			)
			{
				_temperature     = temperature;
				_humidity        = humidity;
				_pressure        = pressure;
				_gasResistance   = gasResistance;
				_proximity       = proximity;
				_smokeLevel      = smokeLevel;
				_distance        = distance;
			}

void Data::printData(){
	  time_t t = time(NULL);
	  struct tm tm = *localtime(&t);
    
    std::cout <<  tm.tm_year + 1900 << "/" << 
                  std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << "/" <<
                  std::setfill('0') << std::setw(2) << tm.tm_mday << " " << 
                  std::setfill('0') << std::setw(2) << tm.tm_hour << ":" << 
                  std::setfill('0') << std::setw(2) << tm.tm_min << ":" << 
                  std::setfill('0') << std::setw(2) << tm.tm_sec;

    std::cout << " Temperature: "<< _temperature <<" degC"
              << ", Humidity: "<< _humidity <<" %rH"
              << ", Pressure: "<< _pressure <<" hPa"
              << ", Gas resistance: "<< _gasResistance <<" kOhms"
              << ", Proximity: "<< _proximity <<" %"
              << ", Smoke level: "<< _smokeLevel <<" %"
              << ", Distance: "<< _distance <<" m"<<std::endl;
}

std::string Data::toString(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  std::stringstream ss;
  ss << tm.tm_year + 1900 << "/" << 
                  std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << "/" <<
                  std::setfill('0') << std::setw(2) << tm.tm_mday << " " << 
                  std::setfill('0') << std::setw(2) << tm.tm_hour << ":" << 
                  std::setfill('0') << std::setw(2) << tm.tm_min << ":" << 
                  std::setfill('0') << std::setw(2) << tm.tm_sec
                  << " Temperature: "<< _temperature <<" °C"
                  << ", Humidity: "<< _humidity <<" %rH"
                  << ", Pressure: "<< _pressure <<" hPa"
                  << ", Gas resistance: "<< _gasResistance <<" kOhms"
                  << ", Proximity: "<< _proximity <<" %"
                  << ", Smoke level: "<< _smokeLevel <<" %"
                  << ", Distance: "<< _distance <<" m";
                        
  return ss.str();
}

void Data::setTemperature(float temperature)	{ _temperature = temperature; }
void Data::setHumidity(float humidity)			{ _humidity = humidity; }
void Data::setPressure(float pressure)			{ _pressure = pressure; }
void Data::setGasResistance(float gasResistance){ _gasResistance = gasResistance; }
void Data::setProximity(int proximity)			{ _proximity = proximity; }
void Data::setSmokeLevel(int smokeLevel)		{ _smokeLevel = smokeLevel; }
void Data::setDistance(int distance)			{ _distance = distance; }

float Data::getTemperature()					{ return _temperature; }
float Data::getHumidity()						{ return _humidity; }
float Data::getPressure()						{ return _pressure; }
float Data::getGasResistance()					{ return _gasResistance; }
int Data::getProximity()						{ return _proximity; }
int Data::getSmokeLevel()						{ return _smokeLevel; }
int Data::getDistance()							{ return _distance; }

std::string Data::toStringTemperature(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _temperature;
	return ss.str();
}

std::string Data::toStringHumidity(){ 	
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _humidity;
	return ss.str();
}

std::string Data::toStringPressure(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _pressure;
	return ss.str();
}

std::string Data::toStringGasResistance(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _gasResistance;
	return ss.str();
}

std::string Data::toStringProximity(){ 
 	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _proximity;
	return ss.str();
}

std::string Data::toStringSmokeLevel(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _smokeLevel;
	return ss.str();
}

std::string Data::toStringDistance(){ 
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << _distance;
	return ss.str();
}



