/** @file list6001.cpp */
/** Listing 60-1. Copying an auto_ptr Object (Or Not) */
#include <memory>

std::auto_ptr<int> does_this_work(std::auto_ptr<int> const& x)
{
  std::auto_ptr<int> y(x);
  return y;
}

int main()
{
  std::auto_ptr<int> a, b;
  a.reset(new int(42));
  b = does_this_work(a);
}
