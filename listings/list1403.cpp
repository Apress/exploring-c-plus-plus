/** @file list1403.cpp */
/** Listing 14-3. Aligning Words and Counts Neatly */
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

  map<string, int> counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
    ++counts[word];

  // Determine the longest word.
  string::size_type longest(0);
  for (map<string,int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
    if (iter->first.size() > longest)
      longest = iter->first.size();
  
  // For each word/count pair...
  const int count_size(10); // Number of places for printing the count
  for (map<string,int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
    // Print the word, count, newline. Keep the columns neatly aligned.
    cout << setw(longest)    << left  << iter->first <<
            setw(count_size) << right << iter->second << '\n';
}
