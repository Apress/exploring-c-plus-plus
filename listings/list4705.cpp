/** @file list4705.cpp */
/** Listing 47-5. Simple I/O Test of the rational Class Template */
#include <iostream>
#include <istream>
#include <ostream>

#include "rational.hpp"

int main()
{
  rational<int> r;
  while (std::cin >> r)
    std::cout << r << '\n';
}
