/** @file list2202.cpp */
/** Listing 22-2. Overloading Functions in the Manner of a Library-Writer */
#include <algorithm>
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>

bool is_alpha(char ch)
{
  return std::isalpha(ch, std::locale());
}

bool is_alpha(std::string const& str)
{
  for (std::string::const_iterator iter(str.begin()); iter != str.end(); ++iter)
    if (not is_alpha(*iter))
      return false;
  return true;
}

char to_lower(char ch)
{
  return std::tolower(ch, std::locale());
}

std::string to_lower(std::string str)
{
  for (std::string::iterator iter(str.begin()); iter != str.end(); ++iter)
    *iter = to_lower(*iter);
  return str;
}
  
char to_upper(char ch)
{
  return std::toupper(ch, std::locale());
}

std::string to_upper(std::string str)
{
  for (std::string::iterator iter(str.begin()); iter != str.end(); ++iter)
    *iter = to_upper(*iter);
  return str;
}

int main()
{
  std::string str;
  while (std::cin >> str)
  {
    if (is_alpha(str))
      std::cout << "alpha\n";
    else
      std::cout << "not alpha\n";
    std::cout << "lower: " << to_lower(str) << "\nupper: " << to_upper(str) << '\n';
  }
}
