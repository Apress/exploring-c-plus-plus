/** @file list4306.cpp */
/** Listing 43-6. Throwing an Exception for a Zero Denominator */
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <stdexcept>
#include <string>

class rational
{
public:
  class zero_denominator : public std::logic_error
  {
  public:
    zero_denominator(std::string const& what_arg) : logic_error(what_arg) {}
  };

  rational() : numerator_(0), denominator_(1) {}
  rational(int num) : numerator_(num), denominator_(1) {}
  rational(int num, int den) : numerator_(num), denominator_(den)
  {
    if (denominator_ == 0)
      throw zero_denominator("zero denominator");
    reduce();
  }
#include "list4306.code"
};
#endif
