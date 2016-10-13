/** @file list2403.cpp */
/** Listing 24-3. Demonstrating Floating-Point Output */
#include <ios>
#include <iostream>
#include <ostream>

/// Print a floating-point number in three different formats.
/// @param precision the precision to use when printing @p value
/// @param value the floating-point number to print
void print(int precision, float value)
{
  std::cout.precision(precision);
  std::cout << std::scientific << value << '\t'
            << std::fixed      << value << '\t';

  // Set the format to general.
  std::cout.unsetf(std::ios_base::floatfield);
  std::cout << value << '\n';
}

/// Main program.
int main()
{
  print(6, 123456.789f);
  print(4, 1.23456789f);
  print(2, 123456789.f);
  print(5, -1234.5678e9f);
}
