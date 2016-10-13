#include "power10.hpp"
#include "test.hpp"

void test_power10()
{
  TEST(power10<0>::value == 1);
  TEST(power10<1>::value == 10);
  TEST(power10<2>::value == 100);
  TEST(power10<3>::value == 1000);
  TEST(power10<4>::value == 10000);
}
