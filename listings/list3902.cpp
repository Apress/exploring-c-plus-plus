/** @file list3902.cpp */
/** Listing 39-2. The main Function for the ID-generating Program in the main.cpp file */
#include <iostream>
#include <ostream>

class generate_id
{
public:
  generate_id() : counter_(0) {}
  long next();
private:
  short counter_;
  static short prefix_;
  static long int const max_counter_ = 32767;
};

int main()
{
  generate_id gen;           // Create an ID generator
  for (int i = 0; i != 10; ++i)
    std::cout << gen.next() << '\n';
}
