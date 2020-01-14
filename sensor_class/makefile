all: main.o sensor.o callback.o data.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o
	g++ -o main main.o sensor.o callback.o data.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o

main.o: main.cpp  
	g++ -c main.cpp
 
sensor.o: sensor.cpp sensor.h
	g++ -c sensor.cpp
 
data.o: data.cpp data.h
	g++ -c data.cpp
 
apds9960_sensor.o: apds9960_sensor.cpp apds9960_sensor.h
	g++ -c apds9960_sensor.cpp

bme680.o: ../bme680_controller/bme680.c ../bme680_controller/bme680.h ../bme680_controller/bme680_defs.h
	gcc -c ../bme680_controller/bme680.c 
 
bme680_sensor.o: bme680_sensor.cpp ../bme680_controller/bme680.h 
	gcc -c bme680_sensor.cpp 
 
dht11_sensor.o: dht11_sensor.cpp dht11_sensor.h
	g++ -c dht11_sensor.cpp
 
ds18b20_sensor.o: ds18b20_sensor.cpp ds18b20_sensor.h
	g++ -c ds18b20_sensor.cpp

clean:
	rm main main.o sensor.o data.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o