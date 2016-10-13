/** @file list4301.cpp */
/** Listing 43-1. Accessing an Element of a Vector */
#include <vector>

int main()
{
  std::vector<int> data;
  data.push_back(10);
  data.push_back(20);
  data.at(5) = 0;
}
