/** @file list4408.cpp */
/** Listing 44-8. The Prefix Increment Operator for rational */
rational& rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}
