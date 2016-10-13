/** @file list4005.cpp */
/** Listing 40-5. Rewriting the sanitize Function as a Function Object */
// Copy the initial portion of Listing 21-2 here, including print_counts,
// but stopping just before sanitize.
#include "list4005.code"

/** Base class to hold a locale object. */
class function
{
public:
  function(std::locale loc) : locale_(loc) {}
  bool isalnum(char ch) const { return std::isalnum(ch, locale()); }
  char tolower(char ch) const { return std::tolower(ch, locale()); }
private:
  std::locale const& locale() const { return locale_; }
  std::locale locale_;
};
/** Test for non-letter. */
class non_letter : public function
{
public:
  non_letter(std::locale loc) : function(loc) {}
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
  lowercase(std::locale loc) : function(loc) {}
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
  sanitizer(std::locale loc) : function(loc), non_letter_(loc), lowercase_(loc) {}
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
