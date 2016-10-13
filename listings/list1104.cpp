/** @file list1104.cpp */
/** Listing 11-4. Using Short-circuiting to Test for Non-zero Vector Elements */
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;
  data.insert(data.begin(),
              std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>());

  std::vector<int>::iterator iter;
  for (iter = data.begin(); iter != data.end() and *iter == 0; ++iter)
    /*empty*/;
  if (iter == data.end())
    std::cout << "data contains all zeroes\n";
  else
    std::cout << "data does not contain all zeroes\n";
}
