#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(BME680)
{
  RUN_TEST_CASE(BME680, InitFunction);
  RUN_TEST_CASE(BME680, DurationCalculationZero);
  RUN_TEST_CASE(BME680, DurationCalculationFirstBranch);
  RUN_TEST_CASE(BME680, DurationCalculationSecondBranchNoLoop);
  RUN_TEST_CASE(BME680, DurationCalculationSecondBranchLoop);
}