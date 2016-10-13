/** @file list1203.cpp */
/** Listing 12-3. Local Variable Definitions in a Nested Block */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int main()
{
  std::vector<int> data;
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>());

  std::sort(data.begin(), data.end());

  {
    // Print the sorted vector all on one line. Start the line with "{" and
    // end it with "}". Separate elements with commas. An empty vector prints
    // as "{ }".
    std::cout << '{';
    std::string separator(" ");
    for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
    {
      std::cout << separator << *iter;
      separator = ", ";
    }
    std::cout << " }\n";
  }
  // Cannot use separator out here.
}
