/** @file list4202.cpp */
/** Listing 42-2. Advancing an Iterator */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

#include "data.hpp"
#include "sequence.hpp"

int main()
{
  intvector data(10);
  std::generate(data.begin(), data.end(), sequence(0, 2)); // fill with even numbers 
  intvec_iterator iter(data.begin());
  std::advance(iter, 4);
  std::cout << *iter << ", ";
  std::advance(iter, -2);
  std::cout << *iter << '\n';
}
