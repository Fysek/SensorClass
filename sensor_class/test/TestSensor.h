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
#include "../sensor_factory.h"
#include "../sensor.h"

using namespace CppUnit;

class TestSensor : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSensor);
	
    CPPUNIT_TEST(testSensorConstructor);
    CPPUNIT_TEST(testSensorDestructor);
	
    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testSensorConstructor(void);
		void testSensorDestructor(void);
		
};

//-----------------------------------------------------------------------------
