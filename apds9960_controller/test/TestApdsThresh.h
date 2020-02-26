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

class TestApdsThresh : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestApdsThresh);

    CPPUNIT_TEST(testGetGestureEnterThresh);
    CPPUNIT_TEST(testSetGestureEnterThresh);
    CPPUNIT_TEST(testGetGestureExitThresh);
    CPPUNIT_TEST(testSetGestureExitThresh);
    CPPUNIT_TEST(testGetLightIntLowThresh);
    CPPUNIT_TEST(testSetLightIntLowThresh);
    CPPUNIT_TEST(testGetLightIntHighThresh);
    CPPUNIT_TEST(testSetLightIntHighThresh);
	CPPUNIT_TEST(testSetProxIntLowThresh);
    CPPUNIT_TEST(testGetProxIntLowThresh);
    CPPUNIT_TEST(testSetProxIntHighThresh);
    CPPUNIT_TEST(testGetProxIntHighThresh);
    
    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testGetGestureEnterThresh(void);
		void testSetGestureEnterThresh(void);
		void testGetGestureExitThresh(void);
		void testSetGestureExitThresh(void);
		void testGetLightIntLowThresh(void);
		void testSetLightIntLowThresh(void);
		void testGetLightIntHighThresh(void);
		void testSetLightIntHighThresh(void);
		void testSetProxIntLowThresh(void);
		void testGetProxIntLowThresh(void);
		void testSetProxIntHighThresh(void);
		void testGetProxIntHighThresh(void);
		
	private:
		APDS9960_RPi *mTestObj;
};
