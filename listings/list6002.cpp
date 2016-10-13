/** @file list6002.cpp */
/** Listing 60-2. The Correct Way to Copy auto_ptr Objects */
#include <memory>

std::auto_ptr<int> does_this_work(std::auto_ptr<int> x)
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
