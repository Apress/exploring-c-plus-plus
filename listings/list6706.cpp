/** @file list6706.cpp */
/** Listing 67-6. Using Metaprogramming to Implement vector’s insert Function */
// is_integral<T>::type is true_type if T is an integral type, or false_type
// if T is any other type. A const type is the same as the base type.
class true_type  {};
class false_type {};
template<class T>
struct is_integral {
   typedef false_type type;
};
template<> struct is_integral<int>          { typedef true_type type; };
template<> struct is_integral<char>         { typedef true_type type; };
template<> struct is_integral<unsigned int> { typedef true_type type; };
// etc. for all the built-in integral types

template<class T>
template<class InputIterator>
void vector<T>::do_insert(iterator pos, InputIterator first, InputIterator last,
                          false_type const&)
{
    // The real function is more complicated because it must handle exceptions
    // that might be thrown in the middle of copying. But you get the idea.
    for ( ; first != last; ++first)
        pos = insert(pos, *first);
}

template<class T>
template<class IntType>
void vector<T>::do_insert(iterator pos, IntType first, IntType last,
                          true_type const&)
{
    // Cast to an exact match to the other insert function.
    insert(pos, static_cast<size_type>(first),
           static_cast<value_type const&>(last));
}

template<class T>
template<class InputIterator>
void vector<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
   do_insert(pos, first, last, is_integral<InputIterator>::type());
}
