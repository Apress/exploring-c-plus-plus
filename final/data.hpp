/** @file data.hpp */
/** Listing 41-2. The data.hpp file to support integer data */
#ifndef DATA_HPP_
#define DATA_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

/// Convenient shorthand for a vector of integers.
typedef std::vector<int> intvector;

/// Convenient shorthand for an intvector’s iterator.
typedef intvector::iterator intvec_iterator;

/// Read a series of values from the standard input into @p data,
/// overwriting @p data in the process.
/// @param[in,out] data a sequence container of values
template<class Container>
void read_data(Container& data)
{
  data.clear();
  data.insert(data.begin(), std::istream_iterator<typename Container::value_type>(std::cin),
              std::istream_iterator<typename Container::value_type>());
}

/// Write a container of values to the standard output. Write all values on one
/// line, separated by single space characters, and surrounded by curly braces,
/// e.g., { 1 2 3 }.
/// @param[in] data a container of values
template<class Container>
void write_data(Container const& data)
{
  std::cout << "{ ";
  std::copy(data.begin(), data.end(),
            std::ostream_iterator<typename Container::value_type>(std::cout, " "));
  std::cout << "}\n";
}
#endif
