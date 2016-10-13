/** @file list3702.cpp */
/** Listing 37-2. Defining Classes for height and weight */
#include <iostream>
#include <ostream>

/// Height in centimeters
class height
{
public:
  height(int h) : value_(h) {}
  int value() const { return value_; }
private:
  int value_;
};

/// Weight in kilograms
class weight
{
public:
  weight(int w) : value_(w) {}
  int value() const { return value_; }
private:
  int value_;
};

/// Body-mass index
class bmi
{
public:
  bmi() : value_(0) {}
  bmi(height h, weight w) : value_(w.value() * 10000 / (h.value()*h.value())) {}
  int value() const { return value_; }
private:
  int value_;
};
height operator+(height a, height b)
{
  return height(a.value() + b.value());
}
int operator/(height a, height b)
{
  return a.value() / b.value();
}
std::istream& operator>>(std::istream& in, height& h)
{
  int tmp;
  if (in >> tmp)
    h = tmp;
  return in;
}
std::ostream& operator<<(std::ostream& out, bmi i)
{
  out << i.value();
  return out;
}
// Implement other operators similarly, but implement only
// the ones that make sense.
weight operator-(weight a, weight b)
{
  return weight(a.value() - b.value());
}
#include "list3702.code"

int main()
{
  std::cout << "Height in centimeters: ";
  height h(0);
  std::cin >> h;

  std::cout << "Weight in kilograms: ";
  weight w(0);
  std::cin >> w;

  std::cout << "Body-mass index = " << bmi(h, w) << '\n';
}
