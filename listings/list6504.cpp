/** @file list6504.cpp */
/** Listing 65-4. Rewriting abs to Take Advantage of a Using Declaration */
namespace numeric {
  template<class T>
  rational<T> abs(rational<T> const& r)
  {
    using namespace std;
    return rational<T>(abs(r.numerator()), r.denominator());
  }
}
