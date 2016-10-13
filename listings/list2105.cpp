/** @file list2105.cpp */
/** Listing 21-5. Testing for Palindromes */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>

/** Test for non-letter.
 * @param ch the character to test
 * @return true if @p ch is not a letter
 */
bool non_letter(char ch)
{
  return not isalpha(ch, std::locale());
}

/** Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale());
}

/** Compare two characters without regard to case. */
bool same_char(char a, char b)
{
  return lowercase(a) == lowercase(b);
}

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string str)
{
  std::string::iterator end(std::remove_if(str.begin(), str.end(), non_letter));
  std::string rev(str.begin(), end);
  std::reverse(rev.begin(), rev.end());
  return not rev.empty() and std::equal(str.begin(), end, rev.begin(), same_char);
}

int main()
{
  std::locale::global(std::locale(""));
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());

  std::string line;
  while (std::getline(std::cin, line))
    if (is_palindrome(line))
      std::cout << line << '\n';
}
