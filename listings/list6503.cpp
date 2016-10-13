/** @file list6503.cpp */
/** Listing 65-3. Equivalent Code to the Instantiation of abs(rational<integer>) */
rational<integer> abs(rational<integer> const& r)
{
  return rational<integer>(std::abs(r.numerator()), r.denominator());
}
