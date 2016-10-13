/** @file list5307.cpp */
/** Listing 53-7. Testing Collation Order of Wide Strings */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>
#include <vector>

std::wstring widen(std::string const& narrow)
{
  return std::wstring(narrow.begin(), narrow.end());
}

void sort_words(std::vector<std::wstring> words, std::locale loc)
{
  std::sort(words.begin(), words.end(), loc);
  std::wcout << widen(loc.name()) << L":\n";
  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::wstring, wchar_t>(std::wcout, L"\n"));
}

int main()
{
  using namespace std;
  vector<wstring> words;
  words.push_back(L"circus");
  words.push_back(L"\u00e5ngstrom");     // ångstrom
  words.push_back(L"\u00e7irc\u00ea");   // çircê
  words.push_back(L"angle");
  words.push_back(L"essen");
  words.push_back(L"ether");
  words.push_back(L"\u00e6ther");        // æther
  words.push_back(L"aether");
  words.push_back(L"e\u00dfen");         // eßen

  sort_words(words, locale::classic());
  sort_words(words, locale("en_GB.utf8"));  // Great Britain
  sort_words(words, locale("no_NO.utf8"));  // Norway
}
