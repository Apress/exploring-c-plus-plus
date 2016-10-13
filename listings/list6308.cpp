/** @file list6308.cpp */
/** Listing 63-8. The assignment_mixin Class Template */
template<class T>
class assignment_mixin {
public:
   T& operator=(T rhs)
   {
      rhs.swap(static_cast<T&>(*this));
      return static_cast<T&>(*this);
   }
};
