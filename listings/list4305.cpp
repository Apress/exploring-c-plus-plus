/** @file list4305.cpp */
/** Listing 43-5. Using an I/O Stream Exception Mask */
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
  std::cin.exceptions(std::ios_base::badbit);
  std::cout.exceptions(std::ios_base::badbit);

  int x(0);
  try
  {
    while (std::cin >> x)
      std::cout << x << '\n';
    if (not std::cin.eof()) // failure without eof means invalid input
      std::cerr << "Invalid integer input. Program terminated.\n";
  }
  catch(std::ios_base::failure const& ex)
  {
    std::cerr << "Major I/O failure! Program terminated.\n";
    std::terminate();
  }
}
