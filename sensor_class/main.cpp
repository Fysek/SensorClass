#include "sensor.h"
#include "sensor_factory.h"

const int BME680_I2C_ADDR = 0x76;
const int APDS9960_I2C_ADDR = 0x39;
const int numberOfMeasurements = 20;

int main(){
    Data dataSensors;
    char *outputFile = "log.txt";
    int i=0;
    std::string output;
    
	SensorFactory *sensorFactory;
	Sensor *sensorBME680;
	Sensor *sensorAPDS9960;

	sensorBME680 = sensorFactory->CreateSensor(ST_BME680);
	sensorBME680->startConnection();
	sensorBME680->I2CSetAddress(BME680_I2C_ADDR);
	sensorBME680->configure();
	
	sensorAPDS9960 = sensorFactory->CreateSensor(ST_APDS9960);
	sensorAPDS9960->I2CSetAddress(APDS9960_I2C_ADDR);
	sensorAPDS9960->startConnection();
	sensorAPDS9960->configure();
	
    while(i<numberOfMeasurements){
      sensorBME680->measure(4, 1, dataSensors, outputFile);
      sensorAPDS9960->measure(3, 1, dataSensors, outputFile);
      output = dataSensors.toString();
      std::cout<< output << std::endl;
      i++;
    } 
    
    sensorBME680->stopConnection();
	sensorFactory->DestroySensor(sensorBME680);
	
	sensorAPDS9960->stopConnection();
	sensorFactory->DestroySensor(sensorAPDS9960);
	
    return 0;
}
