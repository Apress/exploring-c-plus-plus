/** @file list5801.cpp */
/** Listing 58-1. Silly Program to Demonstrate Memory Leaks */
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

int* read(std::istream& in)
{
  int value;
  if (in >> value)
    return new int(value);
  else
    return 0;
}

int divide(int x, int y)
{
  return x / y;
}

int main()
{
  std::cout << "Enter pairs of numbers, and I will divide them.\n";
  std::string line;
  while(std::getline(std::cin, line))
  {
    std::istringstream input(line);
    if (int* x = read(input))
      if (int* y = read(input))
        std::cout << divide(*x, *y) << '\n';
  }
}
