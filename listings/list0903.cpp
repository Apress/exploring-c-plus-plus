/** @file list0903.cpp */
/** Listing 9-3. Sorting Integers, Using Iterators to Print the Results */
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;     // initialized to be empty
  int x(0);

  // Read integers one at a time.
  while (std::cin >> x)
    // Store each integer in the vector.
    data.push_back(x);

  // Sort the vector.
  std::sort(data.begin(), data.end());

  // Print the vector, one number per line.
  for (std::vector<int>::iterator i(data.begin()); i != data.end(); ++i)
    std::cout << *i << '\n';
}
