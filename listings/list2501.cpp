/** @file list2501.cpp */
/** Listing 25-1. Documenting Your Code with Doxygen */
/** @file
 * @brief Test strings to see whether they are palindromes.
 * Read lines from the input, strip non-letters, and check whether
 * the result is a palindrome. Ignore case differences when checking.
 * Echo palindromes to the standard output.
 */

/** @mainpage Palindromes
 * Test input strings to see whether they are palindromes. 
 *
 * A palindrome is a string that reads the same forward and backward.
 * To test for palindromes, this program needs to strip punctuation and
 * other non-essential characters from the string, and compare letters without
 * regard to case differences.
 *
 * This program reads lines of text from the standard input and echos
 * to the standard output those lines that are palindromes.
 *
 * Source file: @link palindrome.cpp palindrome.cpp @endlink
 *
 * @date 14-June-2006
 * @author Ray Lischner
 * @version 1.0
 */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>

/** @brief Test for non-letter.
 * Test the character @p ch in the global locale.
 * @param ch the character to test
 * @return true if @p ch is not a letter
 */
bool non_letter(char ch)
{
  return not isalnum(ch, std::locale());
}

/** @brief Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase. This approach does not solve the eszet
 * problem (German eszet is a lowercase character that converts
 * to two uppercase characters), but it's the best we can do in
 * standard C++.
 *
 * All conversions use the global locale.
 *
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale());
}

/** @brief Compare two characters without regard to case.
 * The comparison is limited by the lowercase() function.
 * @param a one character to compare
 * @param b the other character to compare
 * @return @c true if the characters are the same in lowercase,
 *         @c false if they are different.
 */
bool same_char(char a, char b)
{
  return lowercase(a) == lowercase(b);
}

/** @brief Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return @c true if @p str is the same forward and backward
 */
bool is_palindrome(std::string str)
{
  std::string::iterator end(std::remove_if(str.begin(), str.end(), non_letter));
  std::string rev(end - str.begin(), ' ');
  std::reverse_copy(str.begin(), end, rev.begin());
  return not rev.empty() and std::equal(str.begin(), end, rev.begin(), same_char);
}

/** @brief Main program.
 * Set the global locale to the user's native locale. Then imbue the I/O streams
 * with the native locale.
 */
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
