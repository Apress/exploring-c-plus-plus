/** @file list6703.cpp */
/** Listing 67-3. Testing the power10 Class Template */
#include "power10.hpp"
#include "test.hpp"

int main()
{
  test(power10<0>::value == 1);
  test(power10<1>::value == 10);
  test(power10<2>::value == 100);
  test(power10<3>::value == 1000);
  test(power10<9>::value == 1000000000);
}
