/** @file list6705.cpp */
/** Listing 67-5. The fixed Class Template */
#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "power10.hpp"

template<class T=long, int N=4>
class fixed
{
public:
  class fixed_error : std::runtime_error
  {
  public:
    fixed_error(std::string const& arg) : runtime_error(arg) {}
  };
  typedef T value_type;                              ///< Type of the actual value
  static int const places = N;                       ///< number of decimal places
  static value_type const places10 = power10<N>::value;  ///< 10<sup>places</sup>

  fixed();
  fixed(value_type integer);
  fixed(value_type integer, value_type fraction);
  fixed(double value);
  template<class U, int M>
  fixed(fixed<U, M> const& rhs);

  template<class U, int M>
  fixed& operator=(fixed<U, M> rhs);

  std::string as_string() const;
  bool read(std::istream& strm);
  /// Convert to some other type, especially floating point.
  template<class U>
  U convert() const;

  /// Round off to the nearest integer.
  value_type round() const;

  /// Return the integer part (without rounding).
  value_type integer() const;
  /// Return the fraction part to @p M decimal places.
  template<int M>
  value_type fraction() const;
  /// Return the fraction part to @p N (or @p places ) decimal places.
  value_type fraction() const { return fraction<places>(); }

  fixed& operator+=(fixed f);
  fixed& operator-=(fixed f);
  fixed& operator*=(fixed f);
  fixed& operator/=(fixed f);

  fixed& operator+=(T i);
  fixed& operator-=(T i);
  fixed& operator*=(T i);
  fixed& operator/=(T i);

  void negate();

  fixed& operator++();
  fixed operator++(int);
  fixed& operator--();
  fixed operator--(int);

  /// Return the internal value.
  value_type value();

private:
  value_type reduce(value_type frac);
  value_type make_value(value_type integer, value_type fraction);
  value_type value_;
};


/// Negate a fixed value
template<class T, int N>
fixed<T,N> operator-(fixed<T,N> a);

template<class T, int N>
std::istream& operator>>(std::istream& strm, fixed<T,N>& f);

/// Write a fixed value
template<class T, int N>
std::ostream& operator<<(std::ostream& strm, fixed<T,N> f);

/// Add fixed values
template<class T, int N> fixed<T,N> operator+(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> fixed<T,N> operator+(fixed<T,N> a, T b);
template<class T, int N> fixed<T,N> operator+(T a, fixed<T,N> b);

/// Subtract fixed values
template<class T, int N> fixed<T,N> operator-(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> fixed<T,N> operator-(fixed<T,N> a, T b);
template<class T, int N> fixed<T,N> operator-(T a, fixed<T,N> b);

/// Multiply fixed values
template<class T, int N> fixed<T,N> operator*(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> fixed<T,N> operator*(fixed<T,N> a, T b);
template<class T, int N> fixed<T,N> operator*(T a, fixed<T,N> b);

/// Divide fixed values
template<class T, int N> fixed<T,N> operator/(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> fixed<T,N> operator/(fixed<T,N> a, T b);
template<class T, int N> fixed<T,N> operator/(T a, fixed<T,N> b);

template<class T, int N> bool operator==(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator==(fixed<T,N> a, T b);
template<class T, int N> bool operator==(T a, fixed<T,N> b);
template<class T, int N> bool operator!=(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator!=(fixed<T,N> a, T b);
template<class T, int N> bool operator!=(T a, fixed<T,N> b);
template<class T, int N> bool operator<(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator<(fixed<T,N> a, T b);
template<class T, int N> bool operator<(T a, fixed<T,N> b);
template<class T, int N> bool operator>(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator>(fixed<T,N> a, T b);
template<class T, int N> bool operator>(T a, fixed<T,N> b);
template<class T, int N> bool operator<=(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator<=(fixed<T,N> a, T b);
template<class T, int N> bool operator<=(T a, fixed<T,N> b);
template<class T, int N> bool operator>=(fixed<T,N> a, fixed<T,N> b);
template<class T, int N> bool operator>=(fixed<T,N> a, T b);
template<class T, int N> bool operator>=(T a, fixed<T,N> b);

#endif
