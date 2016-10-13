/** @file list6507.cpp */
/** Listing 65-7. Qualifying Dependent Names */
#include <iostream>
#include <ostream>
#include <string>

class base
{
public:
  base(std::string const& x = std::string()) : label_(x) {}
  std::string label() const { return label_; }
  void init(base const& b)  { std::cout << "base::init(" << b.label() << ")\n"; }
private:
  std::string label_;
};

std::ostream& operator<<(std::ostream& out, base const& b)
{
  return out << b.label();
}

template<class T>
void init(T const& x)
{
  std::cout << "global init(" << x << ")\n";
}

template<class T>
class demo : T
{
public:
  demo(T const& x) { this->init(x); }
};

int main()
{
  demo<base> d1(base("d1"));
}
