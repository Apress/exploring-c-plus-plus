/** @file list5101.cpp */
/** Listing 51-1. Specializing the hash Template for the rational Type */
#include <array>
#include "rational.hpp"
namespace std {
namespace tr1 {

template<class T>
class hash<rational<T> >
{
public:
  std::size_t operator()(rational<T> const& r)
  const
  {
    return hasher_(r.numerator()) + hasher_(r.denominator());
  }
private:
  std::tr1::hash<T> hasher_;
};
} // end of tr1
} // end of std
