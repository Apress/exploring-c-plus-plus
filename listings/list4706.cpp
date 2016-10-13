/** @file list4706.cpp */
/** Listing 47-6. Testing rational Comparison Operator */
#include <iostream>
#include <istream>
#include <ostream>

#include "rational.hpp"

int main()
{
  rational<int> r;
  while (std::cin >> r)
    if (r != 0)
      std::cout << r << '\n';
}
