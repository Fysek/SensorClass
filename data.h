#ifndef DATA_H
#define DATA_H

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
			float 				temperature,
			float 				humidity,
			float 				pressure,
			int 				gasResistance,
			int 				proximity,
			int 				smokeLevel,
			int 				distance,
			std::vector<int>	auxData
		)		
};  

#endif