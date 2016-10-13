/** @file list3502.cpp */
/** Listing 35-2. Printing Messages from Constructors to Illustrate Order of Construction */
#include <iostream>
#include <ostream>

class base
{
public:
  base() { std::cout << "base::base()\n"; }
};

class middle : public base
{
public:
  middle() { std::cout << "middle::middle()\n"; }
};

class derived : public middle
{
public:
  derived() { std::cout << "derived::derived()\n"; }
};

int main()
{
  derived d;
}
