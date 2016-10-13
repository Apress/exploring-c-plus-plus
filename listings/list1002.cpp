/** @file list1002.cpp */
/** Listing 10-2. Erroneous Program that Applies Decrement to an Output Iterator */
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;
  data.push_back(10);
  data.push_back(42);
  std::ostream_iterator<int> out(std::ostream_iterator<int>(std::cout, ""));
  std::copy(data.begin(), data.end(), out);
  --out;
}
