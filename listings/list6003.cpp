/** @file list6003.cpp */
/** Listing 60-3. Working with shared_ptr */
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

class see_me
{
public:
  see_me(int x) : x_(x) { std::cout <<  "see_me(" << x_ << ")\n"; }
  ~see_me()             { std::cout << "~see_me(" << x_ << ")\n"; }
  int value() const     { return x_; }
private:
  int x_;
};

std::tr1::shared_ptr<see_me> does_this_work(std::tr1::shared_ptr<see_me> x)
{
  std::tr1::shared_ptr<see_me> y(x);
  return y;
}

int main()
{
  std::tr1::shared_ptr<see_me> a, b;
  a.reset(new see_me(42));
  b = does_this_work(a);
  std::vector<std::tr1::shared_ptr<see_me> > v;
  v.push_back(a);
  v.push_back(b);
}
