/** @file list6408.cpp */
/** Listing 64-8. The array_storage Class Template */
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

template<class Char, std::size_t MaxSize>
class array_storage {
public:
   typedef Char array_type[MaxSize];
   typedef std::size_t size_type;
   typedef Char value_type;
   typedef Char* iterator;
   typedef Char const* const_iterator;

   array_storage() : size_(0), string_() { string_[0] = Char(); }

   void swap(array_storage& storage) {
      // linear complexity
      std::swap_ranges(string_.begin(), string_.end(), storage.string_.begin());
      std::swap(size_, storage.size_);
   }
   size_type max_size() const { return MaxSize - 1; }
   void reserve(size_type size) {
     if (size > max_size()) throw std::length_error("reserve");
   }
   void resize(size_type newsize, value_type value) {
      if (newsize > max_size())
         throw std::length_error("resize");
      if (newsize > size_)
         std::fill(begin() + size_, begin() + newsize, value);
      size_ = newsize;
      string_[size_] = Char();
   }
   Char const* c_str() const { return &string_[0]; }

   iterator begin()             { return &string_[0]; }
   const_iterator begin() const { return &string_[0]; }
   iterator end()               { return begin() + size_; }
   const_iterator end() const   { return begin() + size_; }

private:
   size_type size_;
   array_type string_;
};
