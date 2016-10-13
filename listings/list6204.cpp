/** @file list6204.cpp */
/** Listing 62-4. The Language Class with All Enhancements */
#ifndef LANGUAGE_HPP_
#define LANGUAGE_HPP_
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

class language {
public:
   enum type { apl, low=apl, c, cpp, forth, haskell, jovial, lisp, high=lisp };
   language() : value_(low) {}
   language(type value) : value_(value) {}
   language(std::string const& str) : value_(from_string(str)) {}

   language& operator=(language::type value) {
      if (value < low or value > high)
         throw std::out_of_range("language assignment out of range");
      value_ = value;
      return *this;
   }

   language& operator++() {
      if (value_ == high)
         throw std::overflow_error("language::operator++ overflow");
      value_ = type(value_ + 1);
      return *this;
   }
   language operator++(int) { language tmp(*this); ++*this; return tmp; }
   language& operator--() {
      if (value_ == low)
         throw std::underflow_error("language::operator-- underflow");
      value_ = type(value_ - 1);
      return *this;
   }
   language operator--(int) { language tmp(*this); --*this; return tmp; }

   operator type() const { return value_; }

   std::string const& to_string() const { return to_string_.at(value_); }

   static type from_string(std::string const& str) const {
      map::const_iterator iter(from_string_.find(str));
      if (iter == from_string_.end())
         throw std::invalid_argument("No such language: " + str);
      else
         return iter->second;
   }

   static void initialize()
   {
      // pre-allocate the vector, so it's easier to fill
      to_string_.resize(high+1, std::string());
      store("apl", apl);
      store("c", c);
      store("cpp", cpp);
      store("forth", forth);
      store("haskell", haskell);
      store("jovial", jovial);
      store("lisp", lisp);
   }

private:
   typedef std::map<std::string, type> map;
   typedef std::vector<std::string> vector;

   type value_;

   static void store(std::string const& str, type value)
   {
      from_string_[str] = value;
      to_string_.at(value) = str;
   }

   static map from_string_;
   static vector to_string_;
};

bool operator==(language a, language b)
{
   return static_cast<language::type>(a) == static_cast<language::type>(b);
}
bool operator==(language a, language::type b)
{
   return static_cast<language::type>(a) == b;
}
bool operator==(language::type a, language b)
{
   return a == static_cast<language::type>(b);
}

bool operator!=(language a, language b)
{
   return not (a == b);
}
bool operator!=(language a, language::type b)
{
   return not (a == b);
}
bool operator!=(language::type a, language b)
{
   return not (a == b);
}
namespace std {
  template<>
  class less<language> {
  public:
    bool operator()(language a, language b) const {
      return language::type(a) < language::type(b);
    }
  };
}

#endif // LANGUAGE_HPP_
