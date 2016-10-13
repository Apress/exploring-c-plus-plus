/** @file list4710.cpp */
/** Listing 47-10. Defining a Member Constructor Template */
template<class T>
template<class U>
rational<T>::rational(rational<U> const& copy)
: numerator_(copy.numerator()), denominator_(copy.denominator())
{}
