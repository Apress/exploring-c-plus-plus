/** @file list6508.cpp */
/** Listing 65-8. Fix the Mistakes */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <set>

using namespace std;

int begin()
{
   return 0;
}

template<class T>
void insert(T const& container, T::value_type const& value)
{
   container.insert(value);
}

template<class T>
class wrapper : public T
{
public:
   typedef T base;
   typedef base::value_type value_type;
   typedef base::iterator iterator;
   typedef base::const_iterator const_iterator;

   template<class Char, class Traits>
   void load(std::basic_istream<Char, Traits>& stream) {
      value_type x;
      while(stream >> x)
         insert(x);
   }
   template<class Char, class Traits>
   void dump(std::basic_ostream<Char, Traits>& stream) {
      copy(begin(), end(), ostream_iterator<value_type>(stream, "\n"));
   }
};

int main()
{
   wrapper<std::set<int> > data;
   data.load(cin);
   data.dump(cout);
}
