#include "TestApdsNoSensor.h"

using namespace CppUnit;

void TestApdsNoSensor::testConstructor(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getGestureUdDelta());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureLrDelta());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureUdCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureLrCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureNearCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureFarCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureState());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureMotion());
}

void TestApdsNoSensor::testResetGestureParameters(void)
{
    mTestObj->resetGestureParameters();
	
	CPPUNIT_ASSERT(0 == mTestObj->getGestureUdDelta());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureLrDelta());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureUdCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureLrCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureNearCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureFarCount());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureState());
    CPPUNIT_ASSERT(0 == mTestObj->getGestureMotion());
}

void TestApdsNoSensor::testReadAmbientLight(void)
{
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readAmbientLight(val));
}

void TestApdsNoSensor::testReadRedLight(void)
{
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readRedLight(val));
}

void TestApdsNoSensor::testReadGreenLight(void)
{
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readGreenLight(val));
}

void TestApdsNoSensor::testReadBlueLight(void)
{
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readBlueLight(val));
}

void TestApdsNoSensor::testReadProximity(void)
{
	uint8_t val;
	CPPUNIT_ASSERT(true == mTestObj->readProximity(val));
}

//-----------------------------------------------------------------------------

void TestApdsNoSensor::setUp(void)
{
    mTestObj = new APDS9960_RPi();
}

void TestApdsNoSensor::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
