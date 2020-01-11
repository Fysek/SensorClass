# makefile for BME680

all: bme680_main.o bme680.o
	gcc -o bme680 bme680_main.o bme680.o

bme680_main.o: bme680_main.c bme680.h 
	gcc -c bme680_main.c

bme680.o: bme680.c bme680.h bme680_defs.h
	gcc -c bme680.c

clean:
	rm bme680_main.o bme680






