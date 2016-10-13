/** @file list4903.cpp */
/** Listing 49-3. Specializing pair for One void Argument */
template<class U>
struct pair<void, U> {
   typedef void first_type;
   typedef U second_type;
   U second;
   pair();
   pair(U second);
   template<class U2>
   pair(pair<void, U2> const& other);
};
