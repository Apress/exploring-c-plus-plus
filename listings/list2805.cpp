/** @file list2805.cpp */
/** Listing 28-5. Testing the rational Comparison Operators */
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include "test.hpp"

struct rational
{
#include "list2805.code"
};

int main()
{
  rational a(60, 5);
  rational b(12, 1);
  rational c(-24, -2);
  test(a == b);
  test(a >= b);
  test(a <= b);
  test(b <= a);
  test(b >= a);
  test(b == c);
  test(b >= c);
  test(b <= c);
  test(a == c);
  test(a >= c);
  test(a <= c);

  rational d(109, 10);
  test(d < a);
  test(d <= a);
  test(d != a);
  test(a > d);
  test(a >= d);
  test(a != d);

  rational e(241, 20);
  test(e > a);
  test(e >= a);
  test(e != a);
  test(a < e);
  test(a <= e);
  test(a != e);
}
