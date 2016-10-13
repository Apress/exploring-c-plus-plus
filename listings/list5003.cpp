/** @file list5003.cpp */
/** Listing 50-3. Defining Entities in a Namespace */
namespace numeric
{
  template<class T>
  rational<T> operator+(rational<T> const& a, rational<T> const& b)
  {
    rational<T> result(a);
    a += b;
    return a;
  }
}

template<class T>
numeric::rational<T> numeric::operator*(rational<T> const& a, rational<T> const& b)
{
  rational<T> result(a);
  a *= b;
  return a;
}
