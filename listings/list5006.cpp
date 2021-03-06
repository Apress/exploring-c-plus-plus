/** @file list5006.cpp */
/** Listing 50-6. Examples of using Declarations  */
#include <iostream>
#include <ostream>

void print(int i)
{
  std::cout << "int: " << i << '\n';
}

namespace labeled
{
  void print(double d)
  {
    std::cout << "double: " << d << '\n';
  }
}

namespace simple
{
  void print(int i)
  {
    std::cout << i << '\n';
 }
  void print(double d)
  {
    std::cout << d << '\n';
  }
}

void test_simple()
{
  using simple::print;
  print(42);
  print(3.14159);
}

void test_labeled()
{
  using labeled::print;
  print(42);
  print(3.14159);
}

int main()
{
  test_simple();
  test_labeled();
}
