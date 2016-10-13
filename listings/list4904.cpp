/** @file list4904.cpp */
/** Listing 49-4. Specializing pair for the Other void Argument */
template<class T>
struct pair<T, void> {
   typedef T first_type;
   typedef void second_type;
   T first;
   pair();
   pair(T first);
   template<class T2>
   pair(pair<T2, void> const& other);
};
