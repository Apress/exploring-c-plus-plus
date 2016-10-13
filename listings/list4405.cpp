/** @file list4405.cpp */
/** Listing 44-5. Implementing the Multiplication Operator */
rational& rational::operator*=(rational const& rhs)
{
  numerator_ *= rhs.numerator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}
