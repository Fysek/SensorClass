#include "TestApdsSensor.h"

using namespace CppUnit;

void TestApdsSensor::testConstructor(void)
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

void TestApdsSensor::testResetGestureParameters(void)
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

void TestApdsSensor::testEnablePower(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);

	CPPUNIT_ASSERT(true == mTestObj->enablePower());
}

void TestApdsSensor::testDisablePower(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);

	CPPUNIT_ASSERT(true == mTestObj->disablePower());
}

void TestApdsSensor::testConnectFalse(void)
{
	uint8_t address = 0x72;
	
	CPPUNIT_ASSERT(false == mTestObj->connect(address));
}

void TestApdsSensor::testConnectTrue(void)
{
	uint8_t address = 0x39;
	
	CPPUNIT_ASSERT(true == mTestObj->connect(address));
}

void TestApdsSensor::testEnableLightSensorIntTrue(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	CPPUNIT_ASSERT(true == mTestObj->enableLightSensor(true));
}

void TestApdsSensor::testEnableLightSensorIntFalse(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	CPPUNIT_ASSERT(true == mTestObj->enableLightSensor(false));
}

void TestApdsSensor::testDisableLightSensor(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	CPPUNIT_ASSERT(true == mTestObj->disableLightSensor());
}

void TestApdsSensor::testReadAmbientLight(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readAmbientLight(val));
}

void TestApdsSensor::testReadRedLight(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readRedLight(val));
}

void TestApdsSensor::testReadGreenLight(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readGreenLight(val));
}

void TestApdsSensor::testReadBlueLight(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint16_t val;
	CPPUNIT_ASSERT(true == mTestObj->readBlueLight(val));
}

void TestApdsSensor::testReadProximity(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val;
	CPPUNIT_ASSERT(true == mTestObj->readProximity(val));
}

void TestApdsSensor::testGetLEDDrive(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setLEDDrive(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getLEDDrive());
}

void TestApdsSensor::testSetLEDDrive(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setLEDDrive(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getLEDDrive());
}

void TestApdsSensor::testGetLEDBoost(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setLEDBoost(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getLEDBoost());
}

void TestApdsSensor::testSetLEDBoost(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setLEDBoost(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getLEDBoost());
}

void TestApdsSensor::testGetAmbientLightGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setAmbientLightGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getAmbientLightGain());
}

void TestApdsSensor::testSetAmbientLightGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setAmbientLightGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getAmbientLightGain());
}

void TestApdsSensor::testGetProximityGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setProximityGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProximityGain());
}

void TestApdsSensor::testSetProximityGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setProximityGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProximityGain());
}

void TestApdsSensor::testGetProxGainCompEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxGainCompEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxGainCompEnable());
}

void TestApdsSensor::testSetProxGainCompEnable(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxGainCompEnable(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxGainCompEnable());
}

void TestApdsSensor::testGetProxPhotoMask(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxPhotoMask(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxPhotoMask());
}

void TestApdsSensor::testSetProxPhotoMask(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setProxPhotoMask(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getProxPhotoMask());
}

void TestApdsSensor::testGetGestureGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureGain());
}

void TestApdsSensor::testSetGestureGain(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureGain(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureGain());
}

void TestApdsSensor::testGetGestureLEDDrive(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureLEDDrive(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureLEDDrive());
}

void TestApdsSensor::testSetGestureLEDDrive(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureLEDDrive(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureLEDDrive());
}

void TestApdsSensor::testGetGestureWaitTime(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureWaitTime(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureWaitTime());
}

void TestApdsSensor::testSetGestureWaitTime(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureWaitTime(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureWaitTime());
}

void TestApdsSensor::testSetGestureMode(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x01;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureMode(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureMode());
}

void TestApdsSensor::testGetGestureMode(void)
{
	uint8_t address = 0x39;
	mTestObj->connect(address);
	
	uint8_t val=0x00;
	
	CPPUNIT_ASSERT(true == mTestObj->setGestureMode(val));
	
	CPPUNIT_ASSERT(val == mTestObj->getGestureMode());
}



//-----------------------------------------------------------------------------

void TestApdsSensor::setUp(void)
{
    mTestObj = new APDS9960_RPi();
}

void TestApdsSensor::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------
