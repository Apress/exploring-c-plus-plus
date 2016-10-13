/** @file list6407.cpp */
/** Listing 64-7. The deque_storage Class Template */
template<class Char>
class deque_storage {
public:
   typedef std::size_t size_type;
   typedef Char value_type;
   typedef typename std::deque<Char>::iterator iterator;
   typedef typename std::deque<Char>::const_iterator const_iterator;

   deque_storage() : string_() {}

   void swap(deque_storage& storage) { string_.swap(storage.string_); }
   size_type max_size() const        { return string_.max_size(); }
   void reserve(size_type size)      { string_.reserve(size); }
   void resize(size_type size, value_type value) { string_.resize(size, value); }
   Char const* c_str() const {
      data_.assign(begin(), end()); 
      data_.push_back(Char());
      return &data_[0];
   }

   iterator begin()             { return string_.begin(); }
   const_iterator begin() const { return string_.begin(); }
   iterator end()               { return string_.end(); }
   const_iterator end() const   { return string_.end(); }

private:
   std::deque<Char> string_;
   std::vector<Char> data_;
};
