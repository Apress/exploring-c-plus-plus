/** @file list4902.cpp */
/** Listing 49-2. Specializing pair<> for Two void Arguments */
template<>
struct pair<void, void> {
   typedef void first_type;
   typedef void second_type;
   // The implicity default and copy constructors work for this specialization.
};
