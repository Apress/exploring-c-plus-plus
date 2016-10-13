/** @file list4203.cpp */
/** Listing 42-3. Printing the Middle Item of a Series of Integers */
#include <iostream>
#include <ostream>

#include "data.hpp"

int main()
{
  intvector data;
  read_data(data);
  const intvec_iterator iter(data.begin());
  std::advance(iter, data.size() / 2); // move to middle of vector
  if (not data.empty())
    std::cout << "middle item = " << *iter << '\n';
}
