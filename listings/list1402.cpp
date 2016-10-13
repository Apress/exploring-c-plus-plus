/** @file list1402.cpp */
/** Listing 14-2. Printing Word Frequencies */
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;

  map<string, int> counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
    ++counts[word];

  // For each word/count pair...
  for (map<string,int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
    // Print the word, tab, the count, newline.
    cout << iter->first << '\t' << iter->second << '\n';
}
