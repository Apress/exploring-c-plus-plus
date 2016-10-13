/** @file list0806.cpp */
/** Listing 8-6. A copy of Listing 8-5, but Using Member Functions  */
#include <iostream>
#include <ostream>

int main()
{
  using namespace std;

  cout.fill('0');
  cout.width(6);
  cout << 42 << '\n';
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.width(6);
  cout << 42 << '\n';
  cout << 42 << '\n';
  cout.fill('-');
  cout.width(4);
  cout << -42 << '\n';
}
