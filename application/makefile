.PHONY = all clean
CC = g++
LINKERFLAG = -lcrypto -lssl -lpaho-mqtt3as -lpaho-mqttpp3 -lwiringPi

all: main.o callback.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o
	$(CC) -o main main.o callback.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o ${LINKERFLAG}  

main.o: main.cpp 
	$(CC) -c main.cpp  
 
callback.o: ../mqtt/callback.cpp 
	$(CC) -c ../mqtt/callback.cpp 
 
sensor.o: ../sensor_class/sensor.cpp 
	$(CC) -c ../sensor_class/sensor.cpp 
	
sensor_factory.o: ../sensor_class/sensor_factory.cpp 
	$(CC) -c ../sensor_class/sensor_factory.cpp	

data.o: ../sensor_class/data.cpp 
	${CC} -c ../sensor_class/data.cpp

apds9960_rpi.o: ../apds9960_controller/apds9960_rpi.cpp 
	$(CC) -c ../apds9960_controller/apds9960_rpi.cpp	 
 
apds9960_sensor.o: ../sensor_class/apds9960_sensor.cpp 
	$(CC) -c ../sensor_class/apds9960_sensor.cpp

bme680.o: ../bme680_controller/bme680.c 
	$(CC) -c ../bme680_controller/bme680.c 
 
bme680_sensor.o: ../sensor_class/bme680_sensor.cpp 
	$(CC) -c ../sensor_class/bme680_sensor.cpp 
 
dht11_sensor.o: ../sensor_class/dht11_sensor.cpp 
	$(CC) -c ../sensor_class/dht11_sensor.cpp
 
ds18b20_sensor.o: ../sensor_class/ds18b20_sensor.cpp 
	$(CC) -c ../sensor_class/ds18b20_sensor.cpp

clean:
	rm main main.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o
