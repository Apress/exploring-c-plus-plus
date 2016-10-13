/** @file list2303.cpp */
/** Listing 23-3. Using Overloading to Distinguish Types of Integer Literals */
#include <iostream>
#include <locale>
#include <ostream>

void print(int i)
{
  std::cout << "int=" << i << '\n';
}

void print(long l)
{
  std::cout << "long=" << l << '\n';
}

int main()
{
  std::cout.imbue(std::locale(""));
  print(0);
  print(0L);
  print(32768);
  print(-32768);
  print(2147483647);
  print(-2147483647);
  // The following lines might work on your system.
  // If you are feeling adventuresome, uncomment the next 3 lines:
  // print(2147483648);
  // print(9223372036854775807);
  // print(-9223372036854775807);
}
