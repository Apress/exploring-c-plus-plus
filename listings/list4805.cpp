/** @file list4805.cpp */
/** Listing 48-5. The Primary std::less Class Template */
template<class T>
struct less {
   bool operator()(T const& a, T const& b) const { return a < b; }
};
