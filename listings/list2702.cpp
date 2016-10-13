/** @file list2702.cpp */
/** Listing 27-2. Using a Class and Its Members */
#include <iostream>
#include <ostream>

/// Represent a rational number.
struct rational
{
  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive
};

int main()
{
  rational pi;
  pi.numerator = 355;
  pi.denominator = 113;
  std::cout << "pi is about " << pi.numerator << "/" << pi.denominator << '\n';
}
