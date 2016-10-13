/** @file list6701.cpp */
/** Listing 67-1. Excerpt of the fixed Class Template */
template<class T, int N>
class fixed
{
public:
  typedef T value_type;
  static T const places = N;
  static T const places10 = power10<N>::value;

  fixed() : value_(0) {}
  fixed(value_type integer) : value_(integer * places10) {}

  value_type integer()  const { return value() / places10; }
  value_type fraction() const;
  value_type value()    const { return value_; }
private:
  value_type value_;
};

template<class T, int N>
typename fixed<T, N>::value_type fixed<T, N>::fraction()
const
{
  return std::abs(value()) % places10;
}
