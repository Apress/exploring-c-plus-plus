/** @file list5102.cpp */
/** Listing 51-2. Using a Hint Position When Inserting into a Set */
#include <iostream>
#include <istream>
#include <set>
#include <string>

int main()
{
  std::string word;
  std::set<std::string> words;

  std::set<std::string>::iterator hint(words.begin());
  while(std::cin >> word)
    hint = words.insert(hint, word);
}
