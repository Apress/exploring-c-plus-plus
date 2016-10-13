/** @file list5306.cpp */
/** Listing 53-6. Demonstrating How Collation Order Depends on Locale */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>
#include <vector>

void sort_words(std::vector<std::string> words, std::locale loc)
{
  std::sort(words.begin(), words.end(), loc);
  std::cout << loc.name() << ":\n";
  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main()
{
  using namespace std;
  vector<string> words;
  words.push_back("circus");
  words.push_back("\u00e5ngstrom");     // ångstrom
  words.push_back("\u00e7irc\u00ea");   // çircê
  words.push_back("angle");
  words.push_back("essen");
  words.push_back("ether");
  words.push_back("\u00e6ther");        // æther
  words.push_back("aether");
  words.push_back("e\u00dfen");         // eßen

  sort_words(words, locale::classic());
  sort_words(words, locale("en_GB.utf8"));  // Great Britain
  sort_words(words, locale("no_NO.utf8"));  // Norway
}
