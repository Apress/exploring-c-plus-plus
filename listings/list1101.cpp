/** @file list1101.cpp */
/** Listing 11-1. Printing bool Values */
#include <ios>
#include <iostream>
#include <ostream>

int main()
{
  std::cout << "true=" << true << '\n';
  std::cout << "false=" << false << '\n';
  std::cout << std::boolalpha;
  std::cout << "true=" << true << '\n';
  std::cout << "false=" << false << '\n';
}
