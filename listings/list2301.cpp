/** @file list2301.cpp */
/** Listing 23-1. Discovering the Number of Bits in an Integer */
#include <iostream>
#include <limits>
#include <ostream>

int main()
{
  std::cout << "bits per int = ";
  if (std::numeric_limits<int>::is_signed)
    std::cout << std::numeric_limits<int>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<int>::digits << '\n';

  std::cout << "bits per bool = ";
  if (std::numeric_limits<bool>::is_signed)
    std::cout << std::numeric_limits<bool>::digits + 1 << '\n';
  else
    std::cout << std::numeric_limits<bool>::digits << '\n';
}
