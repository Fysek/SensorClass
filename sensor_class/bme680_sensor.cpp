#include "bme680_sensor.h"

int BME680_I2CHandler;

void BME680::startConnection(){
	BME680_I2CHandler = open("/dev/i2c-1", O_RDWR);
	if (BME680_I2CHandler < 0) {
		perror("I2C is already opened!");
		exit(1);
	}
}

void BME680::stopConnection(){
	close(BME680_I2CHandler);
}

void BME680::I2CSetAddress(int address){
	if (ioctl(BME680_I2CHandler, I2C_SLAVE, address) < 0) {
		perror("I2C address does not exist!");
		exit(1);
	}
}

void BME680::configure(){
   
  I2CSetAddress(_I2CAddress);   
   
  _SensorSettings.dev_id = _I2CAddress;
  _SensorSettings.intf = BME680_I2C_INTF;
  _SensorSettings.read = &user_i2c_read;
  _SensorSettings.write = &user_i2c_write;
  _SensorSettings.delay_ms = &user_delay_ms;
  
  _configurationResult = bme680_init(&_SensorSettings);
  
  uint8_t set_required_settings;
     
  //Select the power mode 
  //Must be set before writing the sensor configuration 
  _SensorSettings.power_mode = BME680_FORCED_MODE; 
  
  /* Set the temperature, pressure and humidity settings */
  _SensorSettings.tph_sett.os_hum = BME680_OS_2X;
  _SensorSettings.tph_sett.os_pres = BME680_OS_4X;
  _SensorSettings.tph_sett.os_temp = BME680_OS_8X;
  _SensorSettings.tph_sett.filter = BME680_FILTER_SIZE_3;
  
  /* Set the remaining gas sensor settings and link the heating profile */
  _SensorSettings.gas_sett.run_gas = BME680_ENABLE_GAS_MEAS;
  
  // Create a ramp heat waveform in 3 steps 
  _SensorSettings.gas_sett.heatr_temp = 320; //degree Celsius 
  _SensorSettings.gas_sett.heatr_dur = 150; //ms
  
  /* Set the required sensor settings needed */
  set_required_settings = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_FILTER_SEL 
  	| BME680_GAS_SENSOR_SEL;
  
  /* Set the desired sensor configuration */
  _configurationResult = bme680_set_sensor_settings(set_required_settings,&_SensorSettings);
  
  /* Set the power mode */
  _configurationResult = bme680_set_sensor_mode(&_SensorSettings);
  
  /* Get the total measurement duration so as to sleep or wait till the
   * measurement is complete */
}

void BME680::measure(int delay, int nMeas, Data &outputData, char *outputFile){
  
	uint16_t meas_period;
	time_t t = time(NULL);
	struct bme680_field_data data;
	struct tm tm = *localtime(&t);
	int i=0;
	
	bme680_get_profile_dur(&meas_period, &_SensorSettings);
	//user_delay_ms(meas_period + delay*1000);
#if DEBUG
  printf("***Start of measurements with BME680***\n");
#endif	 
	if(outputFile != NULL){
		FILE *f = fopen(outputFile, "a");
		
		if (f == NULL){
			printf("Error opening file!\n");
		}
		else {
			while(i<nMeas) {
				_configurationResult = bme680_get_sensor_data(&data, &_SensorSettings);
				
				if(data.status & BME680_HEAT_STAB_MSK){
					t = time(NULL);
					tm = *localtime(&t);
					outputData.setTemperature(data.temperature / 100.0f);
					outputData.setHumidity(data.humidity / 1000.0f); 
					outputData.setPressure(data.pressure / 100.0f); 
					outputData.setGasResistance(data.gas_resistance);

#if DEBUG
					printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
					printf("T: %.2f degC, P: %.2f hPa, H: %.2f %%rH", data.temperature / 100.0f,
							data.pressure / 100.0f, data.humidity / 1000.0f );
					printf(", G: %d Ohms", data.gas_resistance);
					printf("\r\n");
#endif		
					fprintf(f,"%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
					fprintf(f,"T: %.2f degC, P: %.2f hPa, H: %.2f %%rH", data.temperature / 100.0f, data.pressure / 100.0f, data.humidity / 1000.0f );
					fprintf(f,", G: %d Ohms", data.gas_resistance);
					fprintf(f,"\r\n");
			
				} 
				else {	
					nMeas++;//When setup unstable, add measurement
				}
				i++;
				/*Prepare next measurement*/
				_configurationResult = bme680_set_sensor_mode(&_SensorSettings); 
				user_delay_ms(meas_period + delay*1000); 		
			}
		}
	}		
}


/***************Global functions*******************/

void user_delay_ms(uint32_t period){
    sleep(period/1000);
}   

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){

	int8_t rslt = 0; 
	uint8_t reg[1];
	reg[0]=reg_addr;

 	if (write(BME680_I2CHandler, reg, 1) != 1) {
		perror("user_i2c_read_reg");
		rslt = 1;
	}
	if (read(BME680_I2CHandler, reg_data, len) != len) {
		perror("user_i2c_read_data");
		rslt = 1;
	}

	return rslt;
}

int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){
    
	int8_t rslt = 0; 
	uint8_t reg[16];
    reg[0]=reg_addr;
	
    for (int i=1; i<len+1; i++)
       reg[i] = reg_data[i-1];

    if (write(BME680_I2CHandler, reg, len+1) != len+1) {
		perror("user_i2c_write");
		rslt = 1;
        exit(1);
	}

    return rslt;
}





