#include "TestApdsThresh.h"

using namespace CppUnit;


void TestApdsThresh::testGetGestureEnterThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureEnterThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureEnterThresh());
}

void TestApdsThresh::testSetGestureEnterThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureEnterThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureEnterThresh());
}

void TestApdsThresh::testGetGestureExitThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureExitThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureExitThresh());
}

void TestApdsThresh::testSetGestureExitThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureExitThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureExitThresh());
}

void TestApdsThresh::testGetLightIntLowThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val=0x00;
	mTestObj->setLightIntLowThreshold(val);
	CPPUNIT_ASSERT(true == mTestObj->getLightIntLowThreshold(val));
}

void TestApdsThresh::testSetLightIntLowThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setLightIntLowThreshold(val));
}

void TestApdsThresh::testGetLightIntHighThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val=0x00;
	mTestObj->setLightIntHighThreshold(val);
	CPPUNIT_ASSERT(true == mTestObj->getLightIntHighThreshold(val));
}

void TestApdsThresh::testSetLightIntHighThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setLightIntHighThreshold(val));
}

void TestApdsThresh::testSetProxIntLowThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x0f;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxIntLowThresh(val));
}

void TestApdsThresh::testGetProxIntLowThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x0f;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxIntLowThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxIntLowThresh());
}

void TestApdsThresh::testSetProxIntHighThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);

	uint8_t val=0x0f;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxIntHighThresh(val));
}

void TestApdsThresh::testGetProxIntHighThresh(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x0f;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxIntHighThresh(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxIntHighThresh());
}
//-----------------------------------------------------------------------------

void TestApdsThresh::setUp(void)
{
    mTestObj = new APDS9960_RPi();
}

void TestApdsThresh::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
