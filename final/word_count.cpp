/** @file word_count.cpp */
/** Listing 21-2. New main Function that Sets the Global Locale */
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <locale>
#include <map>
#include <ostream>
#include <string>

typedef std::map<std::string, int>  count_map;  ///< Map words to counts
typedef count_map::iterator         count_iter; ///< Iterate over a @c count_map
typedef std::string::size_type      str_size;   ///< String size type

/** Initialize the I/O streams by imbuing them with
 * the global locale. Use this function to imbue the streams
 * with the native locale. C++ initially imbues streams with
 * the classic locale.
 */
void initialize_streams()
{
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());
}

/** Find the longest key in a map.
 * @param map the map to search
 * @returns the size of the longest key in @p map
 */
str_size get_longest_key(count_map map)
{
  str_size result(0);
  for (count_iter iter(map.begin()); iter != map.end(); ++iter)
    if (iter->first.size() > result)
      result = iter->first.size();
  return result;
}

/** Print the word, count, newline. Keep the columns neatly aligned.
 * Rather than the tedious operation of measuring the magnitude of all
 * the counts and then determining the necessary number of columns, just
 * use a sufficiently large value for the counts column.
 * @param iter an iterator that points to the word/count pair
 * @param longest the size of the longest key; pad all keys to this size
 */
void print_pair(count_iter iter, str_size longest)
{
  const int count_size(10); // Number of places for printing the count
  std::cout << std::setw(longest)    << std::left  << iter->first <<
               std::setw(count_size) << std::right << iter->second << '\n';
}

/** Print the results in neat columns.
 * @param counts the map of all the counts
 */
void print_counts(count_map counts)
{
  str_size longest(get_longest_key(counts));

  // For each word/count pair...
  for (count_iter iter(counts.begin()); iter != counts.end(); ++iter)
    print_pair(iter, longest);
}

/** Listing 40-5. Rewriting the sanitize Function as a Function Object */

/** Base class to hold a locale object. */
class function
{
public:
  /// Cache the locale.
  function(std::locale loc) : locale_(loc) {}
  /// Test for alphanumeric
  /// @param ch the character to test
  /// @return true if @p ch is alphanumeric in the locale
  bool isalnum(char ch) const { return std::isalnum(ch, locale()); }
  /// Convert to lowercase
  /// @param ch the character to convert
  /// @return the character @p ch in lowercase or @p ch unchanged if it has no
  /// lowercase equivalent.
  char tolower(char ch) const { return std::tolower(ch, locale()); }
private:
  std::locale const& locale() const { return locale_; }
  std::locale locale_;
};

/** Test for non-letter. */
class non_letter : public function
{
public:
  /// Cache the locale.
  non_letter(std::locale loc) : function(loc) {}
  /// Test whether @p ch is not a letter.
  /// @param ch The character to test
  /// @return true if @p ch is not a letter, that is, is not alphanumeric.
  bool operator()(char ch)
  const
  {
    return not isalnum(ch);
  }
};

/** Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase.
 */
class lowercase : public function
{
public:
  /// Cache the locale
  lowercase(std::locale loc) : function(loc) {}
  /// Convert to lowercase
  /// @param ch The character to convert.
  /// @return the character @p ch in lowercase or @p ch unchanged if it has no
  /// lowercase equivalent.
  char operator()(char ch)
  const
  {
    return tolower(ch);
  }
};

/** Sanitize a string by keeping only alphabetic characters. */
class sanitizer : public function
{
public:
  /// Cache the locale.
  sanitizer(std::locale loc) : function(loc), non_letter_(loc), lowercase_(loc) {}
  /// Sanitize a string.
  /// Erase non-letter characters, then convert the string to lowercase.
  /// @param str The string to sanitize.
  std::string operator()(std::string str)
  {
    // Remove all non-letters from the string, and then erase them.
    str.erase(std::remove_if(str.begin(), str.end(), non_letter_), str.end());

    // Convert the remnants of the string to lowercase.
    std::transform(str.begin(), str.end(), str.begin(), lowercase_);

    return str;
  }
private:
  non_letter non_letter_;
  lowercase lowercase_;
};

/** Main program to count unique words in the standard input. */
int main()
{
  // Fetch the native locale only once.
  std::locale native(std::locale(""));
  // Use the native locale as the global locale.
  std::locale::global(native);
  initialize_streams();

  count_map counts;
  std::string word;
  sanitizer sanitize(native);

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    std::string copy(sanitize(word));

    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  print_counts(counts);
}
