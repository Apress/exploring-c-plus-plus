/** @file list1003.cpp */
/** Listing 10-3. Reversing the Input Order */
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
       start != end;
       /*empty*/)
  {
    --end;
    if (start != end)
    {
      int tmp = *start;
      *start = *end;
      *end = tmp;
      ++start;
    }
  }

  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
