/** @file list6305.cpp */
/** Listing 63-5. Undefined Behavior Arises from HashableString That Derives from std::string */
#include <iostream>
#include <istream>
#include <set>
#include <string>
#include "HashableString.hpp"

class string_pool
{
public:
   string_pool() : pool_() {}
   ~string_pool() {
      while (not pool_.empty()) {
         std::string* ptr = *pool_.begin();
         pool_.erase(pool_.begin());
         delete ptr;
      }
   }
   std::string* add(std::string const& str) {
      std::string* ptr = new std::string(str);
      pool_.insert(ptr);
      return ptr;
   }
private:
   std::set<std::string*> pool_;
};

int main()
{
   string_pool pool;
   HashableString str;
   while (std::cin >> str)
   {
      std::cout << "hash of \"" << str << "\" = " << str.hash() << '\n';
      pool.add(str);
   }
}
