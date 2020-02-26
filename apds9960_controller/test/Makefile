CXX = g++
LINKFLAGS= -lcppunit -lwiringPi

all: TestMain.o TestApdsInt.o TestApdsThresh.o TestApdsSensor.o TestApdsNoSensor.o apds9960_rpi.o  
	$(CXX) -o TestMain TestMain.o TestApdsInt.o TestApdsThresh.o TestApdsSensor.o  TestApdsNoSensor.o apds9960_rpi.o $(LINKFLAGS)
	
TestMain.o: TestMain.cpp 
	$(CXX) -c TestMain.cpp
	
TestApdsInt.o: TestApdsInt.cpp
	$(CXX) -c TestApdsInt.cpp

TestApdsThresh.o: TestApdsThresh.cpp
	$(CXX) -c TestApdsThresh.cpp
	
TestApdsSensor.o: TestApdsSensor.cpp
	$(CXX) -c TestApdsSensor.cpp

TestApdsNoSensor.o: TestApdsNoSensor.cpp
	$(CXX) -c TestApdsNoSensor.cpp
	
apds9960_rpi.o: ../apds9960_rpi.cpp
	$(CXX) -c ../apds9960_rpi.cpp	
	
clean:
	rm TestMain TestMain.o TestApdsInt.o TestApdsThresh.o TestApdsSensor.o TestApdsNoSensor.o apds9960_rpi.o 