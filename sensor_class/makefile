.PHONY = all clean
CC = gcc
CXX = g++
LINKERFLAG = -lwiringPi

all: main.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o
	${CXX} -o main main.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o ${LINKERFLAG} 

main.o: main.cpp  
	${CXX} -c main.cpp
	
sensor.o: sensor.cpp 
	${CXX} -c sensor.cpp
	
sensor_factory.o: sensor_factory.cpp 
	${CXX} -c sensor_factory.cpp
 
data.o: data.cpp 
	${CXX} -c data.cpp
	
apds9960_rpi.o: ../apds9960_controller/apds9960_rpi.cpp 
	${CXX} -c ../apds9960_controller/apds9960_rpi.cpp	
 
apds9960_sensor.o: apds9960_sensor.cpp 
	${CXX} -c apds9960_sensor.cpp

bme680.o: ../bme680_controller/bme680.c 
	${CC} -c ../bme680_controller/bme680.c 
 
bme680_sensor.o: bme680_sensor.cpp 
	${CXX} -c bme680_sensor.cpp 
 
dht11_sensor.o: dht11_sensor.cpp 
	${CXX} -c dht11_sensor.cpp
 
ds18b20_sensor.o: ds18b20_sensor.cpp 
	${CXX} -c ds18b20_sensor.cpp

clean:
	rm main main.o sensor.o sensor_factory.o data.o apds9960_rpi.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o