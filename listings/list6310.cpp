/** @file list6310.cpp */
/** Listing 63-10. The comparison_mixin and equality_mixin Class Templates */
template<class T>
class comparison_mixin
{
public:
   friend bool operator>(T const& lhs, T const& rhs) { return rhs < lhs; }
   friend bool operator>=(T const& lhs, T const& rhs) { return not (lhs < rhs); }
   friend bool operator<=(T const& lhs, T const& rhs) { return not (rhs < lhs); }
};
template<class T>
class equality_mixin
{
public:
   friend bool operator!=(T const& lhs, T const& rhs) { return not (lhs == rhs); }
};
