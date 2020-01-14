#include "sensor.h"
#include "bme680_sensor.h"
#include "apds9960_sensor.h"
#include "dht11_sensor.h"
#include "ds18b20_sensor.h"


#define BME680_I2C_ADDR UINT8_C(0x76)



int main(){
    BME680 iBME680(BME680_I2C_ADDR);
    APDS9960 iAPDS9960;
    DHT11 iDHT11;
    DS18B20 iDS18B20;
    Data dataBME680;
    char *outputFile = "log.txt";
    int i=0;
    std::string output;
    
   	iBME680.startConnection();
    iBME680.configure();

    
    while(1){
      iBME680.measure(5, 1, dataBME680, outputFile);
      output = dataBME680.toString();

      //std::cout<< output << std::endl;
      i++;
    } 
    
    iBME680.stopConnection();

    return 0;
}
