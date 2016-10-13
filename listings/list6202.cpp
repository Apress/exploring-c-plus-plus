/** @file list6202.cpp */
/** Listing 62-2. The Language Class with Comparison and Assignment */
class language {
public:
   enum type { apl, low=apl, c, cpp, forth, haskell, jovial, lisp, high=lisp };
   language() : value_(low) {}
   language(type value) : value_(value) {}

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
private:
   type value_;
};

bool operator==(language a, language b)
{
   return static_cast<language::type>(a) == static_cast<language::type>(b);
}

bool operator!=(language a, language b)
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
