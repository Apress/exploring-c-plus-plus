/** @file list4201.cpp */
/** Listing 42-1. Comparing Iterators by Using the < Operator */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;
  int x;
  while (std::cin >> x)
    data.push_back(x);

  for (std::vector<int>::iterator start(data.begin()), end(data.end());
       start < end;
       ++start)
  {
    --end; // now end points to a real position, possibly start
    int tmp = *start;
    *start = *end;
    *end = tmp;
  }

  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
