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

class TestApdsNoSensor : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestApdsNoSensor);
	
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testResetGestureParameters);
    CPPUNIT_TEST(testReadAmbientLight);
    CPPUNIT_TEST(testReadRedLight);
    CPPUNIT_TEST(testReadGreenLight);
    CPPUNIT_TEST(testReadBlueLight);
    CPPUNIT_TEST(testReadProximity);
    
    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testConstructor(void);
		void testResetGestureParameters(void);
		void testReadAmbientLight(void);
		void testReadRedLight(void);
		void testReadGreenLight(void);
		void testReadBlueLight(void);
		void testReadProximity(void);
		
	private:
		APDS9960_RPi *mTestObj;
};
