/** @file list6206.cpp */
/** Listing 62-6. Just the I/O Operators for a Language Object */
template<class C, class T>
std::basic_ostream<C, T>&
  operator<<(std::basic_ostream<C, T>& stream, language lang)
{
   stream << lang.to_string();
   return stream;
}

template<class C, class T>
std::basic_istream<C, T>&
  operator>>(std::basic_istream<C, T>& stream, language& lang)
{
   std::string str;
   stream >> str;
   try {
      lang = language(str);
   } catch (std::invalid_argument const&) {
      stream.setstate(stream.failbit);
   }
   return stream;
}
