#include "TestData.h"

using namespace CppUnit;

void TestData::testDefDataConstructor(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getTemperature());
    CPPUNIT_ASSERT(0 == mTestObj->getHumidity());
    CPPUNIT_ASSERT(0 == mTestObj->getPressure());
    CPPUNIT_ASSERT(0 == mTestObj->getGasResistance());
    CPPUNIT_ASSERT(0 == mTestObj->getProximity());
    CPPUNIT_ASSERT(0 == mTestObj->getSmokeLevel());
    CPPUNIT_ASSERT(0 == mTestObj->getDistance());
}

void TestData::testParamDataConstructor(void)
{
	float 	temperature = 25.6;
	float 	humidity = 47.1;
	float 	pressure = 1019.9;
	float 	gasResistance = 564.3;
	int 	proximity = 54;
	int 	smokeLevel = 120;
	int 	distance = 42;
	
	Data *paramTestObj;
	
	paramTestObj = new Data(temperature, humidity, pressure, gasResistance, proximity, smokeLevel, distance);
	
	CPPUNIT_ASSERT(temperature == paramTestObj->getTemperature());
    CPPUNIT_ASSERT(humidity == paramTestObj->getHumidity());
    CPPUNIT_ASSERT(pressure == paramTestObj->getPressure());
    CPPUNIT_ASSERT(gasResistance == paramTestObj->getGasResistance());
    CPPUNIT_ASSERT(proximity == paramTestObj->getProximity());
    CPPUNIT_ASSERT(smokeLevel == paramTestObj->getSmokeLevel());
    CPPUNIT_ASSERT(distance == paramTestObj->getDistance());
	
	delete paramTestObj;
}

void TestData::testNoSetGetTemperature(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getTemperature());
}

void TestData::testSetGetTemperature(void)
{
	float value = 24.3;
	mTestObj->setTemperature(value);
    CPPUNIT_ASSERT(value == mTestObj->getTemperature());
}

void TestData::testNoSetGetHumidity(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getHumidity());
}

void TestData::testSetGetHumidity(void)
{
	float value = 42.7;
	mTestObj->setHumidity(value);
    CPPUNIT_ASSERT(value == mTestObj->getHumidity());
}

void TestData::testNoSetGetPressure(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getPressure());
}

void TestData::testSetGetPressure(void)
{
	float value = 1024.35;
	mTestObj->setPressure(value);
    CPPUNIT_ASSERT(value == mTestObj->getPressure());
}

void TestData::testNoSetGetGasResistance(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getGasResistance());
}

void TestData::testSetGetGasResistance(void)
{
	float value = 642.7;
	mTestObj->setGasResistance(value);
    CPPUNIT_ASSERT(value == mTestObj->getGasResistance());
}

void TestData::testNoSetGetProximity(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getProximity());
}

void TestData::testSetGetProximity(void)
{
	int value = 67;
	mTestObj->setProximity(value);
    CPPUNIT_ASSERT(value == mTestObj->getProximity());
}

void TestData::testNoSetGetSmokeLevel(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getSmokeLevel());
}

void TestData::testSetGetSmokeLevel(void)
{
	int value = 204;
	mTestObj->setSmokeLevel(value);
    CPPUNIT_ASSERT(value == mTestObj->getSmokeLevel());
}

void TestData::testNoSetGetDistance(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getDistance());
}

void TestData::testSetGetDistance(void)
{
	int value = 54;
	mTestObj->setDistance(value);
    CPPUNIT_ASSERT(value == mTestObj->getDistance());
}

void TestData::testToStringTemperature(void)
{
	float value = 21.345;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setTemperature(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringTemperature());
}

void TestData::testToStringHumidity(void)
{
	float value = 45.417;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setHumidity(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringHumidity());
}

void TestData::testToStringPressure(void)
{
	float value = 1021.354;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setPressure(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringPressure());
}

void TestData::testToStringGasResistance(void)
{
	float value = 624.325;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setGasResistance(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringGasResistance());
}

void TestData::testToStringProximity(void)
{
	int value = 57;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setProximity(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringProximity());
}

void TestData::testToStringSmokeLevel(void)
{
	int value = 99;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setSmokeLevel(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringSmokeLevel());
}

void TestData::testToStringDistance(void)
{
	int value = 15;
	std::stringstream ss;
	
	ss << std::fixed << std::setprecision(2) << value;
	std::string result = ss.str();
	
	mTestObj->setDistance(value);
	
	CPPUNIT_ASSERT(result == mTestObj->toStringDistance());
}

//-----------------------------------------------------------------------------

void TestData::setUp(void)
{
    mTestObj = new Data();
}

void TestData::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
