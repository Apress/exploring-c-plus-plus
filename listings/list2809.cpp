/** @file list2809.cpp */
/** Listing 28-9. Constructing a Rational Number from a Floating-point Argument */
struct rational
{
  rational(double r)
  : numerator(static_cast<int>(r * 10000)), denominator(10000)
  {
    reduce();
  }

#include "list2809.code"

};
