#include "sensor.h"
#include "sensor_factory.h"

const int BME680_I2C_ADDR = 0x76;

int main(){
    Data dataBME680;
    char *outputFile = "log.txt";
    int i=0;
    std::string output;
    
	SensorFactory *sensorFactory;
	Sensor *sensor_BME680;

	sensor_BME680 = sensorFactory->CreateSensor(ST_BME680);
	sensor_BME680 -> startConnection();
	sensor_BME680 -> I2CSetAddress(BME680_I2C_ADDR);
	sensor_BME680 -> configure();
	
    while(1){
      sensor_BME680->measure(5, 1, dataBME680, outputFile);
      output = dataBME680.toString();
      std::cout<< output << std::endl;
      i++;
    } 
    
    sensor_BME680->stopConnection();

    return 0;
}
