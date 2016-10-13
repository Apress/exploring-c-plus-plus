/** @file list1701.cpp */
/** Listing 17-1. Counting Words, Restricting Words to Letters and Letter-like Characters */
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
  string okay("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
              "abcdefghijklmnopqrstuvwxyz"
              "0123456789-_");
  while (cin >> word)
  {
    // Make a copy of word, keeping only the characters that appear in okay.
    string copy;
    for (string::iterator w(word.begin()); w != word.end(); ++w)
      if (okay.find(*w) != string::npos)
        copy.push_back(*w);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

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
