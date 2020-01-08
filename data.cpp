#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class Data{
	private:
		float 				_temperature;
		float 				_humidity;
		float 				_pressure;
		int 				_gasResistance;
		int 				_proximity;
		int 				_smokeLevel;
		int 				_distance;
		std::vector<int>	_auxData;

	public:
		Data(
			float 				temperature;
			float 				humidity;
			float 				pressure;
			int 				gasResistance;
			int 				proximity;
			int 				smokeLevel;
			int 				distance;
			std::vector<int>	auxData;)
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
			
			
			
};  