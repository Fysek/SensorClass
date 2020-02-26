#include "TestData.h"

using namespace CppUnit;

void TestApdsClass::testDefDataConstructor(void)
{
    CPPUNIT_ASSERT(0 == mTestObj->getTemperature());
    CPPUNIT_ASSERT(0 == mTestObj->getHumidity());
    CPPUNIT_ASSERT(0 == mTestObj->getPressure());
    CPPUNIT_ASSERT(0 == mTestObj->getGasResistance());
    CPPUNIT_ASSERT(0 == mTestObj->getProximity());
    CPPUNIT_ASSERT(0 == mTestObj->getSmokeLevel());
    CPPUNIT_ASSERT(0 == mTestObj->getDistance());
}

//-----------------------------------------------------------------------------

void TestApdsClass::setUp(void)
{
    mTestObj = new APDS9960_RPi();
}

void TestApdsClass::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
