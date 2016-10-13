/** @file list5807.cpp */
/** Listing 58-7. Using auto_ptr in bomb */
#include <iostream>
#include <memory>
#include <ostream>

class see_me
{
public:
  see_me(int x) : x_(x) { std::cout <<  "see_me(" << x_ << ")\n"; }
  ~see_me()             { std::cout << "~see_me(" << x_ << ")\n"; }
private:
  int x_;
};

class bomb : public see_me
{
public:
  bomb() : see_me(1), a_(new see_me(2)) { throw 0; }
  ~bomb() {}
private:
  std::auto_ptr<see_me> a_;
};

int main()
{
  bomb *b(0);
  try {
    b = new bomb;
  } catch(int) {
    if (b == 0)
      std::cout << "b is null\n";
  }
}
