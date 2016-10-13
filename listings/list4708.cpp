/** @file list4708.cpp */
/** Listing 47-8. Trying to Mix rational Base Types */
#include "rational.hpp"

int main()
{
  rational<int> little;
  rational<long> big;
  big = little;
}
