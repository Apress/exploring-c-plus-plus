/** @file list1703.cpp */
/** Listing 17-3. Using the Native Locale for Output */
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>

int main()
{
  std::cout.imbue(std::locale(""));
  int sum(0);
  int x;
  while (std::cin >> x)
    sum = sum + x;
  std::cout << "sum = " << sum << '\n';
}
