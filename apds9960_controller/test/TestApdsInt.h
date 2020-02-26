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

class TestApdsInt : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestApdsInt);

    CPPUNIT_TEST(testGetAmbientLightIntEnable);
    CPPUNIT_TEST(testSetAmbientLightIntEnable);
    CPPUNIT_TEST(testGetProximityIntEnable);
    CPPUNIT_TEST(testSetProximityIntEnable);
    CPPUNIT_TEST(testGetGestureIntEnable);
    CPPUNIT_TEST(testSetGestureIntEnable);
    CPPUNIT_TEST(testClearAmbientLightInt);
    CPPUNIT_TEST(testClearProximityInt);

    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testGetAmbientLightIntEnable(void);
		void testSetAmbientLightIntEnable(void);
		void testGetProximityIntEnable(void);
		void testSetProximityIntEnable(void);
		void testGetGestureIntEnable(void);
		void testSetGestureIntEnable(void);
		void testClearAmbientLightInt(void);
		void testClearProximityInt(void);

		
	private:
		APDS9960_RPi *mTestObj;
};
