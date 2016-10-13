/** @file list5804.cpp */
/** Listing 58-4. Using the auto_ptr Class Template */
#include <iostream>
#include <memory>
#include <ostream>

class see_me
{
public:
  see_me(int x) : x_(x) { std::cout <<  "see_me(" << x_ << ")\n"; }
  ~see_me()             { std::cout << "~see_me(" << x_ << ")\n"; }
  int value() const     { return x_; }
private:
  int x_;
};

std::auto_ptr<see_me> nothing(std::auto_ptr<see_me> arg)
{
  return arg;
}

template<class T>
std::auto_ptr<T> make(int x)
{
  return std::auto_ptr<T>(new T(x));
}

int main()
{
  std::cout << "program begin...\n";
  std::auto_ptr<see_me> sm(make<see_me>(42));
  std::auto_ptr<see_me> other;
  other = nothing(sm);
  if (sm.get() == 0)
    std::cout << "sm is null, having lost ownership of its pointer\n";
  if (other.get() != 0)
    std::cout << "other now has ownership of the int, " <<
                 other->value() << '\n';
  std::cout << "program ends...\n";
}
