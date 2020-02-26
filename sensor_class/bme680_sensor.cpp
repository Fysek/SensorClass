#include "bme680_sensor.h"

int BME680_I2CHandler;
int BME680_I2CAddress;

BME680::BME680(){
	//nothing here
}

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
	BME680_I2CAddress = address; 
	if (ioctl(BME680_I2CHandler, I2C_SLAVE, address) < 0) {
		perror("I2C address does not exist!");
		exit(1);
	}
}

void BME680::configure(){
   
	m_SensorSettings.dev_id = BME680_I2CAddress;
	m_SensorSettings.intf = BME680_I2C_INTF;
	m_SensorSettings.read = &user_i2c_read;
	m_SensorSettings.write = &user_i2c_write;
	m_SensorSettings.delay_ms = &user_delay_ms;
	
	m_configurationResult = bme680_init(&m_SensorSettings);
	
	uint8_t set_required_settings;
		
	//Select the power mode 
	//Must be set before writing the sensor configuration 
	m_SensorSettings.power_mode = BME680_FORCED_MODE; 
	
	/* Set the temperature, pressure and humidity settings */
	m_SensorSettings.tph_sett.os_hum = BME680_OS_2X;
	m_SensorSettings.tph_sett.os_pres = BME680_OS_4X;
	m_SensorSettings.tph_sett.os_temp = BME680_OS_8X;
	m_SensorSettings.tph_sett.filter = BME680_FILTER_SIZE_3;
	
	/* Set the remaining gas sensor settings and link the heating profile */
	m_SensorSettings.gas_sett.run_gas = BME680_ENABLE_GAS_MEAS;
	
	// Create a ramp heat waveform in 3 steps 
	m_SensorSettings.gas_sett.heatr_temp = 320; //degree Celsius 
	m_SensorSettings.gas_sett.heatr_dur = 150; //ms
	
	/* Set the required sensor settings needed */
	set_required_settings = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_FILTER_SEL 
		| BME680_GAS_SENSOR_SEL;
	
	/* Set the desired sensor configuration */
	m_configurationResult = bme680_set_sensor_settings(set_required_settings,&m_SensorSettings);
	
	/* Set the power mode */
	m_configurationResult = bme680_set_sensor_mode(&m_SensorSettings);
	
	/* Get the total measurement duration so as to sleep or wait till the
	* measurement is complete */
}

void BME680::measure(int delayTime, int nMeas, Data &outputData, char *outputFile){
  
	uint16_t meas_period;
	time_t t = time(NULL);
	struct bme680_field_data data;
	struct tm tm = *localtime(&t);
	int i=0;
	
	bme680_get_profile_dur(&meas_period, &m_SensorSettings);
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
				m_configurationResult = bme680_get_sensor_data(&data, &m_SensorSettings);
				if(data.status & BME680_HEAT_STAB_MSK){
					t = time(NULL);
					tm = *localtime(&t);
					outputData.setTemperature(data.temperature / 100.0f);
					outputData.setHumidity(data.humidity / 1000.0f); 
					outputData.setPressure(data.pressure / 100.0f); 
					outputData.setGasResistance(data.gas_resistance/ 1000.0f);
#if DEBUG
					printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
					printf("T: %.2f degC, P: %.2f hPa, H: %.2f %%rH", data.temperature / 100.0f,
							data.pressure / 100.0f, data.humidity / 1000.0f );
					printf(", G: %f Ohms", data.gas_resistance/ 1000.0f);
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
				m_configurationResult = bme680_set_sensor_mode(&m_SensorSettings); 		
				user_delay_ms(meas_period + delayTime*1000); 					
			}
			fclose(f);
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
