#include "sensor.h"
#include "bme680_sensor.h"
#include "apds9960_sensor.h"
#include "dht11_sensor.h"
#include "ds18b20_sensor.h"

int main(){
    BME680 iBME680;
    APDS9960 iAPDS9960;
    DHT11 iDHT11;
    DS18B20 iDS18B20;
    iBME680.configure();
    iAPDS9960.configure();
    Data data1;

    /*
    int id = iDS18B20.getSensorID();
    std::cout << "ID: " << id << std::endl;*/

    float tmeasure = 10;
    data1.updateData(tmeasure, 0, 0, 30, 0, 20, 0, {});
    data1.printData();
    return 0;
}
