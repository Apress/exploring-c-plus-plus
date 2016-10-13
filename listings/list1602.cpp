/** @file list1602.cpp */
/** Listing 16-2. Echoing Input to Output, One Character at a Time */
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
  std::cin >> std::noskipws;
  char ch;
  while (std::cin >> ch)
    std::cout << ch;
}
