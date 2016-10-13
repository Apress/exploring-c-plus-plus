/** @file list6306.cpp */
/** Listing 63-6. The hash<> Class Template */
template<class T>
class hash
{
public:
   std::size_t operator()(T const& x) const
   {
     return reinterpret_cast<std::size_t>(&x);
   }
};

template<>
class hash<std::string>
{
public:
   std::size_t operator()(std::string const& str) const
   {
      std::size_t h(0);
      for (std::string::const_iterator i(str.begin()); i != str.end(); ++i)
         h = h << 1 | *i;
      return h;
   }
};
