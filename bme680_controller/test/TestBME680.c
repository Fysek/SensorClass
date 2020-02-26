#include "../bme680.h"
#include "../bme680_defs.h"
#include "unity.h"
#include "unity_fixture.h"
#include "TestStubs.h"

TEST_GROUP(BME680);
struct bme680_dev Sensor;

TEST_SETUP(BME680)
{
	
}

TEST_TEAR_DOWN(BME680)
{
}


TEST(BME680, InitFunction)
{
	Sensor.dev_id = BME680_I2C_ADDR_PRIMARY;
	Sensor.intf = BME680_I2C_INTF;
	Sensor.read = user_i2c_read;
	Sensor.write = user_i2c_write;
	Sensor.delay_ms = user_delay_ms;
	TEST_ASSERT_EQUAL_INT(-2, bme680_init(&Sensor));
}

TEST(BME680, DurationCalculationZero)
{
	uint16_t inputDuration = 0;
	uint8_t expectedResult = 0;
	
	uint8_t actualResult = calc_heater_dur(inputDuration);
	
	TEST_ASSERT_EQUAL_INT(expectedResult, actualResult);
}

TEST(BME680, DurationCalculationFirstBranch)
{
	uint16_t inputDuration = 0xfc0;
	uint8_t expectedResult = 0xff;
	
	uint8_t actualResult = calc_heater_dur(inputDuration);
	
	TEST_ASSERT_EQUAL_INT(expectedResult, actualResult);
}

TEST(BME680, DurationCalculationSecondBranchNoLoop)
{
	uint16_t inputDuration = 0x3f;
	uint8_t expectedResult = 0x3f;
	
	uint8_t actualResult = calc_heater_dur(inputDuration);
	
	TEST_ASSERT_EQUAL_INT(expectedResult, actualResult);
}

TEST(BME680, DurationCalculationSecondBranchLoop)
{
	uint16_t inputDuration = 0xf00;
	uint8_t expectedResult = 0xfc;

	uint8_t actualResult = calc_heater_dur(inputDuration);
	
	TEST_ASSERT_EQUAL_INT(expectedResult, actualResult);
}