#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "bme680.h"
// bme680 3 1000 logs.txt

// I2C handler
int i2cHandler;

// open I2C Bus
void i2cOpen()
{
	i2cHandler = open("/dev/i2c-1", O_RDWR);
	if (i2cHandler < 0) {
		perror("I2C is already opened!");
		exit(1);
	}
}

// close I2C Bus
void i2cClose()
{
	close(i2cHandler);
}

// set the I2C slave address for all subsequent I2C device transfers
void i2cSetAddress(int address)
{
	if (ioctl(i2cHandler, I2C_SLAVE, address) < 0) {
		perror("I2C address does not exist!");
		exit(1);
	}
}

void user_delay_ms(uint32_t period)
{
    sleep(period/1000);
}

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */

    uint8_t reg[1];
	reg[0]=reg_addr;

 	if (write(i2cHandler, reg, 1) != 1) {
		perror("user_i2c_read_reg");
		rslt = 1;
	}
	if (read(i2cHandler, reg_data, len) != len) {
		perror("user_i2c_read_data");
		rslt = 1;
	}

    return rslt;
}

int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */

	uint8_t reg[16];
    reg[0]=reg_addr;
	
    for (int i=1; i<len+1; i++)
       reg[i] = reg_data[i-1];

    if (write(i2cHandler, reg, len+1) != len+1) {
		perror("user_i2c_write");
		rslt = 1;
        exit(1);
	}

    return rslt;
}

void write2file(char *outputFile, struct tm tm, struct bme680_field_data data)
{
	// Write measurement to output file if specified.
	if(outputFile != NULL)
	{
		FILE *f = fopen(outputFile, "a");
		if (f == NULL)
		{
			printf("Error opening file!\n");
			//exit(1);
		}
		else
		{
			fprintf(f,"%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fprintf(f,"T: %.2f degC, P: %.2f hPa, H: %.2f %%rH", data.temperature / 100.0f,
					data.pressure / 100.0f, data.humidity / 1000.0f );
			fprintf(f,", G: %d Ohms", data.gas_resistance);
			fprintf(f,"\r\n");
			fclose(f);
		}
	
	}
}

int main(int argc, char *argv[] )
{

	int delay, nMeas;
	char *outputFile = NULL;

	// Input argument parser
	if( argc == 2 ) {
		delay = strtol(argv[1], NULL, 10);
	}
	else if( argc == 3 ) {
		delay = strtol(argv[1], NULL, 10);
		nMeas = strtol(argv[2], NULL, 10);
	}
	else if( argc == 4 ) {
		delay = strtol(argv[1], NULL, 10);
		nMeas = strtol(argv[2], NULL, 10);
		outputFile = argv[3]; 
	}
	else {
		delay = 3;
		nMeas = 3;
	}

    // open Linux I2C device
	i2cOpen();

	// set address of the BME680
	i2cSetAddress(BME680_I2C_ADDR_PRIMARY);

	struct bme680_dev Sensor;

	Sensor.dev_id = BME680_I2C_ADDR_PRIMARY;
	Sensor.intf = BME680_I2C_INTF;
	Sensor.read = user_i2c_read;
	Sensor.write = user_i2c_write;
	Sensor.delay_ms = user_delay_ms;

	int8_t rslt = BME680_OK;
	rslt = bme680_init(&Sensor);

    uint8_t set_required_settings;
    
    //Select the power mode 
	//Must be set before writing the sensor configuration 
	Sensor.power_mode = BME680_FORCED_MODE; 

	/* Set the temperature, pressure and humidity settings */
	Sensor.tph_sett.os_hum = BME680_OS_2X;
	Sensor.tph_sett.os_pres = BME680_OS_4X;
	Sensor.tph_sett.os_temp = BME680_OS_8X;
	Sensor.tph_sett.filter = BME680_FILTER_SIZE_3;

	/* Set the remaining gas sensor settings and link the heating profile */
	Sensor.gas_sett.run_gas = BME680_ENABLE_GAS_MEAS;
	
	// Create a ramp heat waveform in 3 steps 
	Sensor.gas_sett.heatr_temp = 320; //degree Celsius 
	Sensor.gas_sett.heatr_dur = 150; //ms

	/* Set the required sensor settings needed */
	set_required_settings = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_FILTER_SEL 
		| BME680_GAS_SENSOR_SEL;

	/* Set the desired sensor configuration */
	rslt = bme680_set_sensor_settings(set_required_settings,&Sensor);

	/* Set the power mode */
	rslt = bme680_set_sensor_mode(&Sensor);
	
	/* Get the total measurement duration so as to sleep or wait till the
	 * measurement is complete */
	uint16_t meas_period;
	bme680_get_profile_dur(&meas_period, &Sensor);
	
	/* Delay till the measurement is ready */
	user_delay_ms(meas_period + delay*1000); 


	printf("***Start of measurements***\n");

	time_t t = time(NULL);

    struct bme680_field_data data;

	struct tm tm = *localtime(&t);
	
	int i=0;

	while(i<nMeas) {

		// Get sensor data
		rslt = bme680_get_sensor_data(&data, &Sensor);
		
		// Avoid using measurements from an unstable heating setup 
		if(data.status & BME680_HEAT_STAB_MSK)
		{
			t = time(NULL);
			tm = *localtime(&t);
			printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			printf("T: %.2f degC, P: %.2f hPa, H: %.2f %%rH", data.temperature / 100.0f,
					data.pressure / 100.0f, data.humidity / 1000.0f );
			printf(", G: %d Ohms", data.gas_resistance);
			printf("\r\n");
			write2file(outputFile, tm, data);
			
		} else {
			//When setup unstable, add measurement
			nMeas++;
		}
		i++;
		// Trigger next meausurement
		rslt = bme680_set_sensor_mode(&Sensor); 

		// Wait for next meausurement
		user_delay_ms(meas_period + delay*1000); 		

	}

	printf("***End of measurements***\n");

    // close I2C Bus
	i2cClose();
	
	return 0;
}

