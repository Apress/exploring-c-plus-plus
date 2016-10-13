/** @file list5415.cpp */
/** Listing 54-15. Improving from_string by Adding Some Error-Checking */
#include <istream> // for the >> operator
#include <sstream> // for ostringstream
#include <string>  // for basic_string
#include "conversion_error.hpp"

template<class T, class Char, class Traits, class Alloc>
T from_string(std::basic_string<Char, Traits, Alloc> const& str)
{
  std::basic_istringstream<Char, Traits> in(str);
  T result;
  Char extra;
  if (in >> result and not (in >> extra))
    return result;
  else
    throw conversion_error(str);
}
