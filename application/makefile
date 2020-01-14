all: main.o callback.o sensor.o data.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o
	g++ -o main main.o callback.o sensor.o data.o apds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o

main.o: main.cpp
	g++ -c main.cpp -lcrypto -lssl -lpaho-mqtt3as -lpaho-mqttpp3 
 
callback.o: ../mqtt/callback.cpp ../mqtt/callback.h
	g++ -c ../mqtt/callback.cpp -lcrypto -lssl -lpaho-mqtt3as -lpaho-mqttpp3 
 
sensor.o: ../sensor_class/sensor.cpp ../sensor_class/sensor.h
	g++ -c ../sensor_class/sensor.cpp 

data.o: ../sensor_class/data.cpp ../sensor_class/data.h
	g++ -c ../sensor_class/data.cpp
 
apds9960_sensor.o: ../sensor_class/apds9960_sensor.cpp ../sensor_class/apds9960_sensor.h
	g++ -c ../sensor_class/apds9960_sensor.cpp

bme680.o: ../bme680_controller/bme680.c ../bme680_controller/bme680.h ../bme680_controller/bme680_defs.h
	gcc -c ../bme680_controller/bme680.c 
 
bme680_sensor.o: ../sensor_class/bme680_sensor.cpp ../bme680_controller/bme680.h 
	gcc -c ../sensor_class/bme680_sensor.cpp 
 
dht11_sensor.o: ../sensor_class/dht11_sensor.cpp ../sensor_class/dht11_sensor.h
	g++ -c ../sensor_class/dht11_sensor.cpp
 
ds18b20_sensor.o: ../sensor_class/ds18b20_sensor.cpp ../sensor_class/ds18b20_sensor.h
	g++ -c ../sensor_class/ds18b20_sensor.cpp

clean:
	rm main main.o sensor.o data.o pds9960_sensor.o bme680.o bme680_sensor.o dht11_sensor.o ds18b20_sensor.o

