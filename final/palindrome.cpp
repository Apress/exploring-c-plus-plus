/** @file palindrome.cpp */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>

/** Class to test for a palindrome.
 * I converted the functions to a class so I could cache
 * the ctype facet.
 */
template<class Char, class Traits = std::char_traits<Char> >
class palindrome_tester
{
public:
  /// Convenience typedef.
  typedef std::basic_string<Char, Traits> string;

  /** Construct the palindrome tester for the given locale.
   * Cache the locale to use for testing characters.
   * @param locale The locale to use for interpreting characters
   */
  palindrome_tester(std::locale& locale)
  : locale_(locale),
    ctype_(std::use_facet<std::ctype<Char> >(locale_))
  {}

  /** Test for non-letter.
   * @param c the character to test
   * @return true if @p ch is not a letter
   */
  bool isalpha(Char c) const { return ctype_.is(ctype_.alpha, c); }

  /** Convert to lowercase.
   * Use a canonical form by converting to uppercase first,
   * and then to lowercase.
   * @param c the character to convert
   * @return the character converted to lowercase
   */
  Char lowercase(Char c)  const { return ctype_.tolower(ctype_.toupper(c)); }

  /** Determine whether @p str is a palindrome.
   * Only letter characters are tested. Spaces and punctuation don't count.
   * Empty strings are not palindromes because that's just too easy.
   * @param str the string to test
   * @return true if @p str is the same forward and backward
   */
  bool operator()(string const& str)
  const
  {
    if (str.empty())
      return false;
    for (typename string::const_iterator first = str.begin(), last = str.end() - 1; first < last;)
    {
      if (not isalpha(*last))
        --last;
      else if (not isalpha(*first))
        ++first;
      else if (lowercase(*first) != lowercase(*last))
        return false;
      else {
        ++first;
        --last;
      }
    }
    return not str.empty();
  }

private:
  std::locale locale_;
  std::ctype<Char> const& ctype_;
};

int main(int argc, char** argv)
{
  if (argc < 3) {
    std::cerr << "usage: " << argv[0] << "INPUT-FILE OUTPUT-FILE [LOCALE]\n";
    return EXIT_FAILURE;
  }
  std::wifstream in(argv[1]);
  if (not in) {
    std::perror(argv[1]);
    return EXIT_FAILURE;
  }
  std::wofstream out(argv[2]);
  if (not out) {
    std::perror(argv[2]);
    return EXIT_FAILURE;
  }
  std::locale locale(argc >= 4 ? argv[3] : "");
  palindrome_tester<wchar_t> is_palindrome(locale);
  in.imbue(locale);
  in.exceptions(in.badbit);
  out.imbue(locale);
  out.exceptions(out.badbit);

  std::wstring line;
  while (std::getline(in, line))
    if (is_palindrome(line))
      out << line << L'\n';
}
