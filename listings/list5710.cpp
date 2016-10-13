/** @file list5710.cpp */
/** Listing 57-10. Making a Deep Copy */
#include <iostream>
#include <ostream>

class wrapper
{
public:
   wrapper(int x)            : p_(new int(x))         {}
   wrapper(wrapper const& w) : p_(new int(w.value())) {}
   ~wrapper()                                         { delete p_; }
   wrapper& operator=(wrapper w)
   {
      swap(w);
      return *this;
   }
   void swap(wrapper& w)
   {
      int* tmp(w.p_);
      w.p_ = p_;
      p_ = tmp;
   }
   int value() const                                  { return *p_; }
private:
   int* p_;
};

void print(wrapper w)
{
   std::cout << w.value() << '\n';
}

wrapper increment(wrapper w)
{
   return wrapper(w.value() + 1);
}

int main()
{
  wrapper w(42);
  print(increment(w));
}
