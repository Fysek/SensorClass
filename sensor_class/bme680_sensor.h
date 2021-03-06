#ifndef BME680_SENSOR_H
#define BME680_SENSOR_H

#include "sensor.h"
#include "data.h"
#include "../bme680_controller/bme680.h"
#include "../bme680_controller/bme680_defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/i2c-dev.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define DEBUG 0

/*
How to use the sensor:
1. Start connection through I2C.
2. Configure sensor.
3. Execute measurement(s).
4. Stop connection.

Example code:

startConnection();
configure();
while(){
  measure();
}
stopConnection();
*/

class BME680: public Sensor {
  private: 
    struct bme680_dev m_SensorSettings;
    int m_configurationResult=BME680_OK;
   
  public:
	BME680();
	void startConnection() override;
	void stopConnection() override;
    void configure() override;
    void measure(int delayTime, int nMeas, Data &outputData, char *outputFile) override;
	void I2CSetAddress(int address) override; 
};

/*Global functions for sensor configuration*/
void user_delay_ms(uint32_t period);
int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

#endif
