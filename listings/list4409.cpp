/** @file list4409.cpp */
/** Listing 44-9. Postfix Increment and Decrement Operators */
rational rational::operator++(int)
{
  rational result(*this);
  numerator_ += denominator_;
  return result;
}

rational rational::operator--(int)
{
  rational result(*this);
  numerator_ -= denominator_;
  return result;
}
