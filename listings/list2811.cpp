/** @file list2811.cpp */
/** Listing 28-11. Computing the Absolute Value of a Rational Number */
rational absval(rational const& r)
{
  return rational(abs(r.numerator), r.denominator);
}
