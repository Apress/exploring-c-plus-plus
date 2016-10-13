/** @file list3202.cpp */
/** Listing 32-2. Constructing a vector from Two Read Iterators */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  using namespace std;
  vector<int> orig;
  orig.insert(orig.begin(), istream_iterator<int>(cin), istream_iterator<int>());
  vector<int>::iterator zero(find(orig.begin(), orig.end(), 0));
  vector<int> from_zero(zero, orig.end());
  copy(from_zero.begin(), from_zero.end(), ostream_iterator<int>(cout, "\n"));
}
