#include "TestSensorFactory.h"

using namespace CppUnit;

//-----------------------------------------------------------------------------

void TestSensorFactory::testSensorCreator(void)
{
	Sensor *firstTestObj;
	Sensor *secTestObj;
	Sensor *thirdTestObj;
	
	firstTestObj = mTestObj->CreateSensor(ST_DS18B20);
	secTestObj = mTestObj->CreateSensor(ST_BME680);	
	thirdTestObj = mTestObj->CreateSensor(ST_APDS9960);	
		
	CPPUNIT_ASSERT(1 == firstTestObj->getSensorID());
	CPPUNIT_ASSERT(2 == secTestObj->getSensorID());
	CPPUNIT_ASSERT(3 == thirdTestObj->getSensorID());
	
	mTestObj->DestroySensor(firstTestObj);
	mTestObj->DestroySensor(secTestObj);
	mTestObj->DestroySensor(thirdTestObj);
}

void TestSensorFactory::testSensorDestroyerFirst(void)
{
	//Initialize
	Sensor *firstTestObj;
	Sensor *secTestObj;
	Sensor *thirdTestObj;
	Sensor *fourthTestObj;
	
	//Create
	firstTestObj = mTestObj->CreateSensor(ST_DS18B20);
	secTestObj = mTestObj->CreateSensor(ST_BME680);
	thirdTestObj = mTestObj->CreateSensor(ST_APDS9960);
	
	// Check ID
	CPPUNIT_ASSERT(1 == firstTestObj->getSensorID());
	CPPUNIT_ASSERT(2 == secTestObj->getSensorID());
	CPPUNIT_ASSERT(3 == thirdTestObj->getSensorID());
	
	// Delete first sensor
	mTestObj->DestroySensor(firstTestObj);
	
	// Create fourth
	fourthTestObj = mTestObj->CreateSensor(ST_DS18B20);
	
	// Check ID sensor
	CPPUNIT_ASSERT(3 == fourthTestObj->getSensorID());
	
	//Clean
	mTestObj->DestroySensor(secTestObj);
	mTestObj->DestroySensor(thirdTestObj);
	mTestObj->DestroySensor(fourthTestObj);
}

void TestSensorFactory::testSensorDestroyerLast(void)
{
	//Initialize
	Sensor *firstTestObj;
	Sensor *secTestObj;
	Sensor *thirdTestObj;
	Sensor *fourthTestObj;
	
	//Create
	firstTestObj = mTestObj->CreateSensor(ST_DS18B20);
	secTestObj = mTestObj->CreateSensor(ST_BME680);
	thirdTestObj = mTestObj->CreateSensor(ST_APDS9960);
	
	// Check ID
	CPPUNIT_ASSERT(1 == firstTestObj->getSensorID());
	CPPUNIT_ASSERT(2 == secTestObj->getSensorID());
	CPPUNIT_ASSERT(3 == thirdTestObj->getSensorID());
	
	// Delete last sensor
	mTestObj->DestroySensor(thirdTestObj);
	
	// Create fourth
	fourthTestObj = mTestObj->CreateSensor(ST_BME680);
	
	// Check ID sensor
	CPPUNIT_ASSERT(3 == fourthTestObj->getSensorID());
	
	//Clean
	mTestObj->DestroySensor(firstTestObj);
	mTestObj->DestroySensor(secTestObj);
	mTestObj->DestroySensor(fourthTestObj);
}

void TestSensorFactory::setUp(void)
{
    mTestObj = new SensorFactory();
}

void TestSensorFactory::tearDown(void)
{
    delete mTestObj;
}

