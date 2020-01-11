#ifndef DATA_H
#define DATA_H
#include <vector>

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
	    Data();
		Data(float, float, float, int, int, int, int, std::vector<int>);
		void printData();
		void updateData(float, float, float, int, int, int, int, std::vector<int>);
};

#endif
