#include <iostream>
#include "data.h"


Data::Data(){
    _temperature     =0;
    _humidity        =0;
    _pressure        =0;
    _gasResistance   =0;
    _proximity       =0;
    _smokeLevel      =0;
    _distance        =0;
    _auxData         ={};
}

Data::Data(
			float 				temperature,
			float 				humidity,
			float 				pressure,
			int 				gasResistance,
			int 				proximity,
			int 				smokeLevel,
			int 				distance,
			std::vector<int>	auxData
			)
			{
				_temperature     = temperature;
				_humidity        = humidity;
				_pressure        = pressure;
				_gasResistance   = gasResistance;
				_proximity       = proximity;
				_smokeLevel      = smokeLevel;
				_distance        = distance;
				_auxData         = auxData;
			}

void Data::printData(){
    std::cout << "Temperature: "<< _temperature <<"degC"
              << ", Humidity: "<< _humidity <<"%rH"
              << ", Pressure: "<< _pressure <<"hPa"
              << ", Gas resistance: "<< _gasResistance <<"Ohms"
              << ", Proximity: "<< _proximity <<"%"
              << ", Smoke level: "<< _smokeLevel <<"%"
              << ", Distance: "<< _distance <<"m"<<std::endl;

}

void Data::updateData(float t=0, float h=0, float p=0, int gR=0, int pr=0, int s=0, int d=0, std::vector<int> a={}){
	_temperature    =t;
	_humidity       =h;
	_pressure       =p;
	_gasResistance  =gR;
	_proximity      =pr;
	_smokeLevel     =s;
	_distance       =d;
	_auxData        =a;
}

