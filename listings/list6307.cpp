/** @file list6307.cpp */
/** Listing 63-7. Rewriting string_pool to Use hash<> */
#include <iostream>
#include <istream>
#include "hash.hpp"
#include "string_pool.hpp"

int main()
{
   string_pool pool;
   std::string str;
   hash<std::string> hash;
   while (std::cin >> str)
   {
      std::cout << "hash of \"" << str << "\" = " << hash(str) << '\n';
      pool.add(str);
   }
}
