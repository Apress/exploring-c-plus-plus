/** @file list2808.cpp */
/** Listing 28-8. Test Program for Multiplying an Integer and a Rational Number */
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>

struct rational
{
#include "list2808.code"
};

int main()
{
  rational result(3 * rational(1, 3));
  std::cout << result.numerator << '/' << result.denominator << '\n';
}
