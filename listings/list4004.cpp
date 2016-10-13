/** @file list4004.cpp */
/** Listing 40-4. Rewriting the sanitize Function to Make Use of Function Objects */
/** Test for non-letter. */
class non_letter
{
public:
  non_letter(std::locale loc) : locale_(loc) {}
  bool operator()(char ch)
  const
  {
    return not isalnum(ch, locale_);
  }
private:
  std::locale locale_;
};

/** Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase.
 */
class lowercase
{
public:
  lowercase(std::locale loc) : locale_(loc) {}
  char operator()(char ch)
  const
  {
    return std::tolower(ch, locale_);
  }
private:
  std::locale locale_;
};

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a santized copy of the string
 */
std::string sanitize(std::string str)
{
  // Remove all non-letters from the string, and then erase them.
  str.erase(std::remove_if(str.begin(), str.end(), non_letter(std::locale())),
            str.end());

  // Convert the remnants of the string to lowercase.
  std::transform(str.begin(), str.end(), str.begin(), lowercase(std::locale()));

  return str;
}
