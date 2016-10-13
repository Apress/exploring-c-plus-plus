/** @file list3002.cpp */
/** Listing 30-2. Assignment Operator with Explicit Use of this-> */
struct rational
{
#include "list3002.code"
  rational& operator=(rational const& that)
  {
    this->numerator = that.numerator;
    this->denominator = that.denominator;
    return *this;
  }
};
