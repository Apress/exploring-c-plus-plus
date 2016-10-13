/** @file list1903.cpp */
/** Listing 19-3. Using Functions to Clarify the Word-Counting Program */
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
 * the given locale. Use this function to imbue the streams
 * with the native locale. C++ initially imbues streams with
 * the classic locale.
 * @param locale the native locale
 */
void initialize_streams(std::locale locale)
{
  std::cin.imbue(locale);
  std::cout.imbue(locale);
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

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @param loc the locale used to test the characters
 * @return a santized copy of the string
 */
std::string sanitize(std::string str, std::locale loc)
{
  std::string result;
  for (std::string::iterator s(str.begin()); s != str.end(); ++s)
    if (std::isalnum(*s, loc))
      result.push_back(std::tolower(*s, loc));
  return result;
}

/** Main program to count unique words in the standard input. */
int main()
{
  std::locale native("");             // get the native locale
  initialize_streams(native);

  count_map counts;
  std::string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    std::string copy(sanitize(word, native));

    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  print_counts(counts);
}
