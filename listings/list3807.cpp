/** @file list3807.cpp */
/** Listing 38-7. Declaring counter Outside of the generate_id Function */
#include <iostream>
#include <ostream>

int counter;

int generate_id()
{
  ++counter;
  return counter;
}

int main()
{
  for (int i = 0; i != 10; ++i)
    std::cout << generate_id() << '\n';
}
