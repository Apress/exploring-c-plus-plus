/** @file list2304.cpp */
/** Listing 23-4. Using Type Casts */
#include <iostream>
#include <locale>
#include <ostream>

typedef signed char byte;

void print(byte b)
{
  // The << operator treats signed char as a mutant char, and tries to
  // print a character. In order to print the value as an integer, you
  // must cast it to an integer type.
  std::cout << "byte=" << static_cast<int>(b) << '\n';
}

void print(short s)
{
  std::cout << "short=" << s << '\n';
}

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
  print(static_cast<short>(0));
  print(static_cast<byte>(0));
  print(static_cast<byte>(255));
  print(static_cast<short>(65535));
  print(32768);
  print(32768L);
  print(-32768);
  print(2147483647);
  print(-2147483647);
  // The following lines might work on your system.
  // If you are feeling adventuresome, uncomment the next 3 lines:
  // print(2147483648);
  // print(9223372036854775807);
  // print(-9223372036854775807);
}
