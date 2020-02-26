#include "TestSensor.h"

using namespace CppUnit;

//-----------------------------------------------------------------------------

void TestSensor::testSensorConstructor(void)
{
	Sensor *mTestObj;
	Sensor *secTestObj;
	Sensor *thirdTestObj;
	SensorFactory *sensorFactory;
	
	mTestObj = sensorFactory->CreateSensor(ST_DS18B20);
	CPPUNIT_ASSERT(1 == mTestObj->getSensorID());
	
	secTestObj = sensorFactory->CreateSensor(ST_BME680);
	CPPUNIT_ASSERT(2 == secTestObj->getSensorID());
    
	thirdTestObj = sensorFactory->CreateSensor(ST_APDS9960);
	CPPUNIT_ASSERT(3 == thirdTestObj->getSensorID());
	
	delete mTestObj;
	delete secTestObj;
	delete thirdTestObj;
}

void TestSensor::testSensorDestructor(void)
{
	Sensor *mTestObj;
	Sensor *secTestObj;
	Sensor *thirdTestObj;
	Sensor *fourthTestObj;
	SensorFactory *sensorFactory;
	
	mTestObj = sensorFactory->CreateSensor(ST_BME680);
	CPPUNIT_ASSERT(1 == mTestObj->getSensorID());
	
	secTestObj = sensorFactory->CreateSensor(ST_BME680);
	CPPUNIT_ASSERT(2 == secTestObj->getSensorID());
    
	thirdTestObj = sensorFactory->CreateSensor(ST_APDS9960);
	CPPUNIT_ASSERT(3 == thirdTestObj->getSensorID());
	
	delete thirdTestObj;
	
	fourthTestObj = sensorFactory->CreateSensor(ST_DS18B20);
	CPPUNIT_ASSERT(3 == fourthTestObj->getSensorID());
	
	delete mTestObj;
	delete secTestObj;
	delete fourthTestObj;	
}

//-----------------------------------------------------------------------------

void TestSensor::setUp(void)
{
    
}

void TestSensor::tearDown(void)
{
    
}


