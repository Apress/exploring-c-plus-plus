#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <algorithm>
#include <cstdlib>

/// Generate random numbers.
/// The standard rand() function returns random integers in
/// the range [0, RAND_MAX]. The goal is to obtain
/// uniformly-distributed numbers in the range [low, high].
/// To achieve properly distributed numbers, check whether
/// the value rand() returns is in the range [0, (high-low+1)*k]
/// where k is the largest integer such that (high-low+1)*k \< RAND_MAX.
/// If the random number is out of range, discard it and get
/// another one. Then take the value mod (high-low+1) and add
/// low to get the random result.
class randomint
{
public:
  /// Construct a random-number generator to produce numbers in the range [<tt>low</tt>, <tt>high</tt>].
  /// If @p low > @p high the values are reversed.
  /// This class uses the std::rand() function, so you call std::srand() to change the seed.
  randomint(int low, int high);
  /// Generate the next random number generator.
  int operator()() const;
private:
  int const low_;
  int const high_;
  int const mod_;
  int const max_;
};

inline randomint::randomint(int low, int high)
: low_(std::min(low, high)),
  high_(std::max(low, high)),
  mod_(high_ - low_ + 1),
  max_(RAND_MAX - RAND_MAX % mod_)
{}

inline int randomint::operator()()
const
{
  int r;
  while ((r = std::rand()) > max_)
    ;
  return r % mod_ + low_;
}

#endif
