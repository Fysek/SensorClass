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

#include "../sensor.h"
#include "../sensor_factory.h"

using namespace CppUnit;

class TestSensorFactory : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSensorFactory);
	
    CPPUNIT_TEST(testSensorCreator);
    CPPUNIT_TEST(testSensorDestroyerFirst);
    CPPUNIT_TEST(testSensorDestroyerLast);
	
    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testSensorCreator(void);
		void testSensorDestroyerFirst(void);
		void testSensorDestroyerLast(void);
		
	private:
		SensorFactory *mTestObj;
};
//-----------------------------------------------------------------------------
