/** @file list3201.cpp */
/** Listing 32-1. Mystery Program */
#include <iostream>
#include <ostream>

struct point
{
  point()
  : x_(0.0), y_(0.0)
  {
    std::cout << "default constructor\n";
  }
  point(double x, double y)
  : x_(x), y_(y)
  {
    std::cout << "constructor(" << x << ", " << y << ")\n";
  }

  double x_;
  double y_;
};

int main()
{
  point pt();
}
