/** @file list3804.cpp */
/** Listing 38-4. Finding the Mode of a Data Set */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <utility>
#include <vector>

int main()
{
  using namespace std;
  typedef vector<int>::iterator vec_iterator;

  vector<int> data((istream_iterator<int>(cin)), istream_iterator<int>());
  sort(data.begin(), data.end());
  // Find all values equal to 42
  pair<vec_iterator, vec_iterator> const& range(
    equal_range(data.begin(), data.end(), 42)
  );
  if (range.first != range.second)
  {
    // Print the range indices only if at least one value is found.
    cout << "index of start of range: " << range.first  - data.begin() << '\n';
    cout << "index of end of range:   " << range.second - data.begin() << '\n';
  }
  cout << "size of range:           " << range.second - range.first << '\n';
}
