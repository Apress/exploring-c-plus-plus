/** @file list3001.cpp */
/** Listing 30-1. First Version of the Assignment Operator */
struct rational
{
#include "list3001.code"
  rational& operator=(rational const& rhs)
  {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
  }
};
