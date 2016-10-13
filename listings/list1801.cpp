/** @file list1801.cpp */
/** Listing 18-1. Folding Uppercase to Lowercase Prior to Counting Words */
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

  locale native("");             // get the native locale
  cin.imbue(native);             // interpret the input and output according to
  cout.imbue(native);            // the native locale

  count_map counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    string copy;
    for (string::iterator w(word.begin()); w != word.end(); ++w)
      if (isalnum(*w, native))
        copy.push_back(tolower(*w, native));
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    cout << iter->first << '\t' << iter->second << '\n';
}
