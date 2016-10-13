/** @file list3003.cpp */
/** Listing 30-3. Assignment of an Integer to a Rational */
struct rational
{
#include "list3003.code"
  rational& operator=(int num)
  {
    this->numerator = num;
    this->denominator = 1;
    return *this;
  }
};
