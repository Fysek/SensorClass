#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../apds9960_rpi.h"

using namespace CppUnit;

//-----------------------------------------------------------------------------

class TestApdsSensor : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestApdsSensor);
	
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testResetGestureParameters);
    CPPUNIT_TEST(testEnablePower);
    CPPUNIT_TEST(testDisablePower);
    CPPUNIT_TEST(testConnectFalse);
    CPPUNIT_TEST(testConnectTrue);
	CPPUNIT_TEST(testEnableLightSensorIntTrue);
    CPPUNIT_TEST(testEnableLightSensorIntFalse);
    CPPUNIT_TEST(testDisableLightSensor);
    CPPUNIT_TEST(testReadAmbientLight);
    CPPUNIT_TEST(testReadRedLight);
    CPPUNIT_TEST(testReadGreenLight);
    CPPUNIT_TEST(testReadBlueLight);
    CPPUNIT_TEST(testReadProximity);
    CPPUNIT_TEST(testGetLEDDrive);
    CPPUNIT_TEST(testSetLEDDrive);
	CPPUNIT_TEST(testGetLEDBoost);
    CPPUNIT_TEST(testSetLEDBoost);
    CPPUNIT_TEST(testGetAmbientLightGain);
    CPPUNIT_TEST(testSetAmbientLightGain);
    CPPUNIT_TEST(testGetProximityGain);
    CPPUNIT_TEST(testSetProximityGain);
    CPPUNIT_TEST(testGetProxGainCompEnable);
    CPPUNIT_TEST(testSetProxGainCompEnable);
    CPPUNIT_TEST(testGetProxPhotoMask);
    CPPUNIT_TEST(testGetGestureGain);
    CPPUNIT_TEST(testSetGestureGain);
    CPPUNIT_TEST(testGetGestureLEDDrive);
    CPPUNIT_TEST(testSetGestureLEDDrive);
    CPPUNIT_TEST(testGetGestureWaitTime);
    CPPUNIT_TEST(testSetGestureWaitTime);
    CPPUNIT_TEST(testGetGestureMode);
    CPPUNIT_TEST(testSetGestureMode);

    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testConstructor(void);
		void testResetGestureParameters(void);
		void testEnablePower(void);
		void testDisablePower(void);
		void testConnectFalse(void);
		void testConnectTrue(void);
		void testEnableLightSensorIntTrue(void);
		void testEnableLightSensorIntFalse(void);
		void testDisableLightSensor(void);
		void testReadAmbientLight(void);
		void testReadRedLight(void);
		void testReadGreenLight(void);
		void testReadBlueLight(void);
		void testReadProximity(void);
		void testGetLEDDrive(void);
		void testSetLEDDrive(void);
		void testGetLEDBoost(void);
		void testSetLEDBoost(void);
		void testGetAmbientLightGain(void);
		void testSetAmbientLightGain(void);
		void testGetProximityGain(void);
		void testSetProximityGain(void);
		void testGetProxGainCompEnable(void);
		void testSetProxGainCompEnable(void);
		void testGetProxPhotoMask(void);
		void testSetProxPhotoMask(void);
		void testGetGestureGain(void);
		void testSetGestureGain(void);
		void testGetGestureLEDDrive(void);
		void testSetGestureLEDDrive(void);
		void testGetGestureWaitTime(void);
		void testSetGestureWaitTime(void);
		void testGetGestureMode(void);
		void testSetGestureMode(void);

		
	private:
		APDS9960_RPi *mTestObj;
};
