/** @file list3103.cpp */
/** Listing 31-3. Using a Class and its Members */
#include <iostream>
#include <ostream>

struct point
{
  double x;
  double y;
};

int main()
{
  point origin, unity;
  origin.x = 0;
  origin.y = 0;
  unity.x = 1;
  unity.y = 1;
  std::cout << "origin = (" << origin.x << ", " << origin.y << ")\n";
  std::cout << "unity  = (" << unity.x  << ", " << unity.y  << ")\n";
}
