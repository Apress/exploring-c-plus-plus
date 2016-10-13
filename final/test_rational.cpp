#include <cmath>
#include <sstream>

#include "rational.hpp"
#include "test.hpp"

void test_rational()
{
  rational<int> zero;
  rational<int> one(1);
  rational<int> half(10, 20);
  rational<int> third(-10, -30);
  rational<int> minus_one(-10, 10);

  TEST(minus_one == -one);
  TEST(one - one == zero);
  TEST(zero == 0);
  TEST(0 == zero);
  TEST(zero < one);
  TEST(zero <= one);
  TEST(half >= third);
  TEST(half > third);
  TEST(half != third);

  TEST(-half < 0);
  TEST(-half <= 0);
  TEST(half > 0);
  TEST(half >= 0);
  TEST(0 < half);
  TEST(0 <= half);
  TEST(0 != half);
  TEST(half != 0);

  TEST(half * 2 == one);
  TEST(2 * half == one)
  TEST(third * 3 == one);
  TEST(3 / one == 3);
  TEST(one / 3 == third);
  TEST(half + half == one);
  TEST(one - half == half);
  TEST((half + 1) * 2 == 1 / third);

  std::stringstream stream;
  TEST(stream << third);
  TEST(stream.str() == "1/3");
  rational<int> check;
  TEST(stream >> check);
  TEST(check == third);

  rational<long> long_pi(1414847550L, 450359962L);
  rational<short> short_pi(long_pi);
  // The following test works only if short has less precision and range than long.
  TEST(long_pi != short_pi);
  // The following test works if long has >= 32 bits and short has 16 bits.
  TEST(short_pi == rational<short>(3598, 1145));
  rational<short> assign_pi;
  assign_pi = long_pi;
  TEST(short_pi == assign_pi);

  TEST(std::abs(third.as<double>() - 0.333333333) < 0.000000001);

  TEST(++zero == one);
  TEST(zero == one);
  TEST(zero++ == one);
  TEST(zero == 2);
  TEST(--zero == one);
  TEST(zero == one);
  TEST(zero-- == one);
  TEST(zero == 0);

  bool okay(false);
  try {
    // Check that a zero denominator really throws an exception.
    rational<int> impossible(1, 0);
  } catch(rational<int>::zero_denominator const& ex) {
    okay = true;
  }
  TEST(okay);
}
