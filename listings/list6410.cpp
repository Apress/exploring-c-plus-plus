/** @file list6410.cpp */
/** Listing 64-10. Quick and Dirty I/O Functions for newstring */
template<class Char, class Storage, class Traits>
std::basic_istream<Char, Traits>&
   operator>>(std::basic_istream<Char, Traits>& stream,
              newstring<Char, Storage, Traits>& string)
{
   std::basic_string<Char, Traits> tmp;
   if (stream >> tmp)
      string = tmp;
   return stream;
}

template<class Char, class Storage, class Traits>
std::basic_ostream<Char, Traits>&
  operator<<(std::basic_ostream<Char, Traits>& stream,
             newstring<Char, Storage, Traits> const& string)
{
   std::basic_string<Char, Traits> tmp(string.begin(), string.end());
   stream << tmp;
   return stream;
}
