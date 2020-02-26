CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
LINKFLAGS= -lcppunit

all: TestMain.o TestSensor.o TestSensorFactory.o TestData.o TestStubs.o sensor_factory.o sensor.o data.o  
	$(CXX) $(CXXFLAGS) -o TestMain TestMain.o TestSensor.o TestSensorFactory.o TestData.o TestStubs.o sensor_factory.o sensor.o data.o $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)
	
TestMain.o: TestMain.cpp 
	$(CXX) -c TestMain.cpp

TestSensor.o: TestSensor.cpp
	$(CXX) -c TestSensor.cpp
	
TestSensorFactory.o: TestSensorFactory.cpp
	$(CXX) -c TestSensorFactory.cpp	
 
TestData.o: TestData.cpp
	$(CXX) -c TestData.cpp

TestStubs.o: TestStubs.cpp
	$(CXX) -c TestStubs.cpp	
	
sensor_factory.o: ../sensor_factory.cpp 
	$(CXX) -c ../sensor_factory.cpp	
	
sensor.o: ../sensor.cpp 
	$(CXX) -c ../sensor.cpp

data.o: ../data.cpp 
	$(CXX) -c ../data.cpp

clean:
	rm TestMain TestMain.o TestSensor.o TestSensorFactory.o TestData.o sensor_factory.o sensor.o data.o 