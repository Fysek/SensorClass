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

#include "../data.h"

using namespace CppUnit;

//-----------------------------------------------------------------------------

class TestData : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestData);
	
    CPPUNIT_TEST(testDefDataConstructor);
    CPPUNIT_TEST(testParamDataConstructor);
	
    CPPUNIT_TEST(testNoSetGetTemperature);
    CPPUNIT_TEST(testSetGetTemperature);
	
    CPPUNIT_TEST(testNoSetGetHumidity);
    CPPUNIT_TEST(testSetGetHumidity);
	
    CPPUNIT_TEST(testNoSetGetPressure);
    CPPUNIT_TEST(testSetGetPressure);
    
	CPPUNIT_TEST(testNoSetGetGasResistance);
    CPPUNIT_TEST(testSetGetGasResistance);
	
	CPPUNIT_TEST(testNoSetGetProximity);
    CPPUNIT_TEST(testSetGetProximity);
    
	CPPUNIT_TEST(testNoSetGetSmokeLevel);
    CPPUNIT_TEST(testSetGetSmokeLevel);
	
	CPPUNIT_TEST(testNoSetGetDistance);
    CPPUNIT_TEST(testSetGetDistance);
	
    CPPUNIT_TEST(testToStringTemperature);
    CPPUNIT_TEST(testToStringHumidity);
	
    CPPUNIT_TEST(testToStringPressure);
    CPPUNIT_TEST(testToStringGasResistance);
	
    CPPUNIT_TEST(testToStringProximity);
    CPPUNIT_TEST(testToStringSmokeLevel);
	
    CPPUNIT_TEST(testToStringDistance);
    
    CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:		
		void testDefDataConstructor(void);
		void testParamDataConstructor(void);
		
		void testNoSetGetTemperature(void);
		void testSetGetTemperature(void);
		
		void testNoSetGetHumidity(void);
		void testSetGetHumidity(void);
		
		void testNoSetGetPressure(void);
		void testSetGetPressure(void);
		
		void testNoSetGetGasResistance(void);
		void testSetGetGasResistance(void);
		
		void testNoSetGetProximity(void);
		void testSetGetProximity(void);
		
		void testNoSetGetSmokeLevel(void);
		void testSetGetSmokeLevel(void);
		
		void testNoSetGetDistance(void);
		void testSetGetDistance(void);
		
		void testToStringTemperature(void);
		void testToStringHumidity(void);
		
		void testToStringPressure(void);
		void testToStringGasResistance(void);
		
		void testToStringProximity(void);
		void testToStringSmokeLevel(void);
		
		void testToStringDistance(void);

	private:
		Data *mTestObj;
};
