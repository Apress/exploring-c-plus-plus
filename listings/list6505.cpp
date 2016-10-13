/** @file list6505.cpp */
/** Listing 65-5. Using an Unqualified Name in a Function Template */
#include <iostream>
#include <ostream>
#include <string>

class base
{
public:
  base(std::string const& x = std::string()) : label_(x) {}
  std::string label() const { return label_; }
  void init(base const& b) { std::cout << "base::init(" << b.label() << ")\n"; }
private:
  std::string label_;
};

template<class T>
class demo : T
{
public:
  demo(T const& x) { init(x); }
};

template<class T>
void init(T const& x)
{
  std::cout << "global init(" << x << ")\n";
}

int main()
{
  demo<base> d1(base("d1"));
  demo<std::string> d2("d2");
}
