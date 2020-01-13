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
    Data data1;
    char *outputFile = "log.txt";
    
    
   	iBME680.startConnection();
    iBME680.configure();
    iBME680.measure(5, 10, outputFile);
    iBME680.stopConnection();

    /*
    int id = iDS18B20.getSensorID();
    std::cout << "ID: " << id << std::endl;*/

    /*float tmeasure = 10;
    data1.updateData(tmeasure, 0, 0, 30, 0, 20, 0, {});
    data1.printData();*/
    return 0;
}
