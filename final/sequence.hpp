/** @file sequence.hpp */
/** Listing 40-8. The sequence.hpp file */
#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

/// Generate a sequence of integers.
class sequence
{
public:
  /// Construct the functor.
  /// @param start the first value the generator returns
  /// @param step increment the value by this much for each call
  sequence(int start = 0, int step = 1) : value_(start), step_(step) {}
  /// Return the current value in the sequence, and increment the value.
  int operator()()
  {
    int result(value_);
    value_ = value_ + step_;
    return result;
  }
private:
  int value_;
  int const step_;
};

#endif
