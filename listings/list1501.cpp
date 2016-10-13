/** @file list1501.cpp */
/** Listing 15-1. Counting Words, with a Clean Program That Uses typedef */
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string> 

int main()
{
  using namespace std;
  typedef map<string, int>    count_map;
  typedef count_map::iterator count_iter;
  typedef string::size_type   str_size;

  count_map counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
    ++counts[word];

  // Determine the longest word.
  str_size longest(0);
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    if (iter->first.size() > longest)
      longest = iter->first.size();
  
  // For each word/count pair...
  const int count_size(10); // Number of places for printing the count
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    // Print the word, count, newline. Keep the columns neatly aligned.
    cout << setw(longest)    << left << iter->first <<
            setw(count_size) << right << iter->second << '\n';
}
