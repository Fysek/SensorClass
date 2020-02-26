#include "TestApdsInt.h"

using namespace CppUnit;


void TestApdsInt::testGetAmbientLightIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setAmbientLightIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getAmbientLightIntEnable());
}

void TestApdsInt::testSetAmbientLightIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setAmbientLightIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getAmbientLightIntEnable());
}

void TestApdsInt::testGetProximityIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setProximityIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProximityIntEnable());
}

void TestApdsInt::testSetProximityIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setProximityIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProximityIntEnable());
}

void TestApdsInt::testGetGestureIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureIntEnable());
}

void TestApdsInt::testSetGestureIntEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureIntEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureIntEnable());
}

void TestApdsInt::testClearAmbientLightInt(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	CPPUNIT_ASSERT(true == mTestObj->clearAmbientLightInt());
}

void TestApdsInt::testClearProximityInt(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	CPPUNIT_ASSERT(true == mTestObj->clearProximityInt());
	
}
//-----------------------------------------------------------------------------

void TestApdsInt::setUp(void)
{
    mTestObj = new APDS9960_RPi();
}

void TestApdsInt::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
