/** @file list1702.cpp */
/** Listing 17-2.Testing a Character by Calling isalpha  */
#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;
  typedef map<string, int>    count_map;
  typedef count_map::iterator count_iter;

  count_map counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    string copy;
    for (string::iterator w(word.begin()); w != word.end(); ++w)
      if (isalnum(*w, locale("")))
        copy.push_back(*w);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    cout << iter->first << '\t' << iter->second << '\n';
}
