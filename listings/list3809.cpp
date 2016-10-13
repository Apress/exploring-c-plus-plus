/** @file list3809.cpp */
/** Listing 38-9. Using Static Data Members for an ID Generator */
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
  // The counter rolls over at a fairly low value (32,767), to ensure the code
  // is completely portable to all systems. Real code can use a higher value
  // before rolling over, but that involves C++ features that the book has not
  // yet covered.
  static long int const max_counter_ = 32767;
};

// Switch to random-number as the initial prefix for production code.
// short generate_id::prefix_(static_cast<short>(std::rand()));
short generate_id::prefix_(1);
long const generate_id::max_counter_;

long generate_id::next()
{
  if (counter_ == max_counter_)
    counter_ = 0;
  else
    ++counter_;
  return prefix_ * (max_counter_ + 1) + counter_;
}

int main()
{
  generate_id gen;           // Create an ID generator
  for (int i = 0; i != 10; ++i)
    std::cout << gen.next() << '\n';
}
