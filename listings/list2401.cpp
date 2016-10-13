/** @file list2401.cpp */
/** Listing 24-1. Floating-Point Numbers Do Not Always Behave as You Expect */
#include <cassert>
int main()
{
  float a(0.03f);
  float b(10.0f);
  float c(0.3f);
  assert(a * b == c);
}
