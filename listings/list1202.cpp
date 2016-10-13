/** @file list1202.cpp */
/** Listing 12-2. Local Variable Definitions */
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

  // Silly way to sort a vector. Assume that the initial portion
  // of the vector has already been sorted, up to the iterator iter.
  // Find where *iter belongs in the already sorted portion of the vector.
  // Erase *iter from the vector and re-insert it at its sorted position.
  // Use binary search to speed up the search for the proper position.
  // Invariant: elements at indices [0, i) are already sorted.
  for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); )
  {
    // Find where data.at(iter) belongs by calling the standard algorithm
    // lower_bound, which performs a binary search and returns an iterator
    // that points into data at a position where the value should be inserted.
    int value(*iter);
    std::vector<int>::iterator here(std::lower_bound(data.begin(), iter, value));
    iter = data.erase(iter);
    data.insert(here, value);
  }

  // Debugging code: check that the loop is actually sorted. Do this by comparing
  // each element with the preceding element in the vector. 
  for (std::vector<int>::iterator iter(data.begin()), prev(data.end());
       iter != data.end();
      ++iter)
  {
    if (prev != data.end())
      assert(not (*iter < *prev));
     prev = iter;
  }

  // Print the sorted vector all on one line. Start the line with "{" and
  // end it with "}". Separate elements with commas. An empty vector prints as "{ }".
  std::cout << '{';
  std::string separator(" ");
  for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
  {
    std::cout << separator << *iter;
    separator = ", ";
  }
  std::cout << " }\n";
}
