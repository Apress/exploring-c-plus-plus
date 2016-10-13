/** @file list5305.cpp */
/** Listing 53-5. Counting Words Again, This Time with Cached Facets */
// Copy the initial portion of Listing 21-2 here, including print_counts,
// but stopping just before sanitize.

/** Base class to hold a ctype facet. */
class function
{
public:
  function(std::locale loc) : ctype_(std::use_facet<std::ctype<char> >(loc)) {}
  bool isalnum(char ch) const { return ctype_.is(std::ctype_base::alnum, ch); }
  char tolower(char ch) const { return ctype_.tolower(ch); }
private:
  std::ctype<char> const& ctype_;
};
// Copy the rest of Listing 40-5 here, starting with the non_letter class,
// and continuing to the end of the listing.
