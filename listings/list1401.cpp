/** @file list1401.cpp */
/** Listing 14-1. Counting Occurrences of Unique Words */
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  std::map<std::string, int> counts;
  std::string word;
  while (std::cin >> word) 
    ++counts[word];
  // TODO: Print the results.
}
