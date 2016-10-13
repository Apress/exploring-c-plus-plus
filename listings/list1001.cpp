/** @file list1001.cpp */
/** Listing 10-1. Demonstrating the Difference Between Prefix and Postfix Increment */
#include <iostream>
#include <ostream>

int main()
{
  int x = 42;

  std::cout << "x   = " << x   << "\n";
  std::cout << "++x = " << ++x << "\n";
  std::cout << "x   = " << x   << "\n";
  std::cout << "x++ = " << x++ << "\n";
  std::cout << "x   = " << x   << "\n";
}
