/** @file list3004.cpp */
/** Listing 30-4. Overloaded Constructors for rational */
struct rational
{
  rational()
  : numerator(0), denominator(1)
  {/*empty*/}

  rational(int num)
  : numerator(num), denominator(1)
  {/*empty*/}

  rational(int num, int den)
  : numerator(num), denominator(den)
  {
    reduce();
  }
#include "list3004.code"
};
