/** @file list4302.cpp */
/** Listing 43-2. A Bad Way to Access an Element of a Vector */
#include <vector>

int main()
{
  std::vector<int> data;
  data.push_back(10);
  data.push_back(20);
  data[5] = 0;
}
