/** @file list6201.cpp */
/** Listing 62-1. The language Class with Error-Checked Successor Functions */
#include <stdexcept>

class language {
public:
   enum type { apl, low=apl, c, cpp, forth, haskell, jovial, lisp, high=lisp };
   language(type value) : value_(value) {}
   language& operator++() {
      if (value_ == high)
         throw std::overflow_error("language::operator++ overflow");
      value_ = type(value_ + 1);
      return *this;
   }
   language operator++(int) { language tmp(*this); ++*this; return tmp; }
private:
   type value_;
};
