/** @file list6707.cpp */
/** Listing 67-7. Testing Two Types to See Whether They Are the Same */
#include <iostream>
#include <ostream>

template<class T, class U>
struct is_same {
   // Assume the types are different.
   enum t { value = false };
};

template<class T>
struct is_same<T, T> {
    // Partial specialization for when the types are the same
    enum t { value = true };
};

enum x { a };
enum y { b };

int main()
{
   std::cout << is_same<int, int>::value << '\n';
   std::cout << is_same<int, int&>::value << '\n';
   std::cout << is_same<int, unsigned>::value << '\n';
   std::cout << is_same<int, const int>::value << '\n';
   std::cout << is_same<x, y>::value << '\n';
   std::cout << is_same<int, signed>::value << '\n';
}
