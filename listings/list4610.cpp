/** @file list4610.cpp */
/** Listing 46-10. Implementing a Member Function Template */
class rational
{
public:
  rational() : numerator_(0), denominator_(1) {}
  rational(int num) : numerator_(num), denominator_(1) {}
  rational(int num, int den);
  rational(double r);

  template<class T>
  T convert()
  const
  {
    return static_cast<T>(numerator()) / static_cast<T>(denominator());
  }

#include "list4610.code"
};
