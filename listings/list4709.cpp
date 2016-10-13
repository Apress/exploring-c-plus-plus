/** @file list4709.cpp */
/** Listing 47-9. Defining the Assignment Operator Function Template */
template<class T>
template<class U>
rational<T>& rational<T>::operator=(rational<U> const& rhs)
{
  assign(rhs.numerator(), rhs.denominator());
  return *this;
}
