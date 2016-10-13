/** @file list1103.cpp */
/** Listing 11-3. Converting a std::string to bool */
#include <iostream>
#include <ostream>
#include <string>

int main()
{
  std::string empty;
  bool b;

  b = empty;
  std::cout << b << '\n';
}
