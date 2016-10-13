/** @file list6501.cpp */
/** Listing 65-1. Simple Overload of abs for rational Arguments */
namespace numeric {
  template<class T>
  rational<T> abs(rational<T> const& r)
  {
    return rational<T>(std::abs(r.numerator()), r.denominator());
  }
}
