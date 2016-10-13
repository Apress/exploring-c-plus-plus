/** @file list3503.cpp */
/** Listing 35-3. Order of Calling Destructors */
#include <iostream>
#include <ostream>

class base
{
public:
  base()  { std::cout << "base::base()\n"; }
  ~base() { std::cout << "base::~base()\n"; }
};

class middle : public base
{
public:
  middle()  { std::cout << "middle::middle()\n"; }
  ~middle() { std::cout << "middle::~middle()\n"; }
};

class derived : public middle
{
public:
  derived()  { std::cout << "derived::derived()\n"; }
  ~derived() { std::cout << "derived::~derived()\n"; }
};

int main()
{
  derived d;
}
