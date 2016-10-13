/** @file power10.hpp */
/** Listing 67-4. Computing a Power of 10 Efficiently */

#ifndef POWER10_HPP_
#define POWER10_HPP_

template<int N>
struct power10; // forward declaration

/** Metaprogram to compute the square of a value. */
template<int N>
struct square
{
  // A metaprogramming function to square a value.
  enum t { value = N * N };
};

/** Metaprogram to raise 10 to the <tt>N</tt>th.
 * If @p N is even, @p Even is true.
 * This base case is for @p Even == @c false so
 * it computes its value by multiplying @p N - 1 by 10.
 */
template<int N, bool Even>
struct power10_aux
{
  // Primary template is for odd N (Even is false)
  enum t { value = 10 * power10<N - 1>::value };
};

/** Specialization to raise 10 to an even power <tt>N</tt>.
 * Compute the square of @p N so the overall computation
 * has logarithmic complexity, not linear.
 */
template<int N>
struct power10_aux<N, true>
{
  // Specialization when N is even: square the value
  enum t { value = square<power10<N / 2>::value>::value };
};

/** This is the real template.
 * Usage:
 * @code
 * enum { example = power10<3>::value };
 * @endcode
 */
template<int N>
struct power10
{
  enum t { value = power10_aux<N, N % 2 == 0>::value };
};

template<>
struct power10<0>
{
  enum t { value = 1 };
};
#endif
