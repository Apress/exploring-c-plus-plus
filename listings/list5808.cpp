/** @file list5808.cpp */
/** Listing 58-8. Mystery Program That Uses auto_ptr */
#include <iostream>
#include <memory>
#include <ostream>

class mystery
{
public:
  mystery() {}
  mystery(mystery const&) { throw "oops"; }
};

class demo
{
public:
  demo(int* x, mystery m, int* y) : x_(x), m_(m), y_(y) {}
  int x() const { return *x_; }
  int y() const { return *y_; }
private:
  demo(demo const&);             // do not implement
  void operator=(demo const&);   // do not implement
  std::auto_ptr<int> x_;
  mystery            m_;
  std::auto_ptr<int> y_;
};

int main()
{
  demo d(new int(42), mystery(), new int(24));
  std::cout << d.x() << d.y() << '\n';
}
