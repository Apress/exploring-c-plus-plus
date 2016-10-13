/** @file list4105.cpp */
/** Listing 41-5. Finding a Subrange that Matches the First Four Digits of π */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

#include "data.hpp"
#include "randomint.hpp"

int main()
{
  intvector pi(4);
  pi.at(0) = 3;
  pi.at(1) = 1;
  pi.at(2) = 4;
  pi.at(3) = 1;

  intvector data(10000);
  // The randomint functor generates random numbers in the range [0, 9].
  // The details are not germane to this exploration, but feel free to
  // consult the code in randomint.hpp on the book’s web site.
  std::generate(data.begin(), data.end(), randomint(0, 9));

  intvec_iterator iter(std::search(data.begin(), data.end(), pi.begin(), pi.end()));
  if (iter == data.end())
    std::cout << "The integer range does not contain the digits of pi.\n";
  else
  {
    std::cout << "Easy as pi: ";
    std::copy(iter, iter+pi.size(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
  }
}
