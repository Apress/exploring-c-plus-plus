/** @file list0905.cpp */
/** Listing 9-5. Doubling Input Values in a Vector */
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main()
{
   std::vector<int> data;
   int x(0);

   while (std::cin >> x)
      data.push_back(x);

   for (std::vector<int>::iterator i(data.begin()); i != data.end(); ++i)
      *i = *i * 2;

   for (std::vector<int>::iterator i(data.begin()); i != data.end(); ++i)
      std::cout << *i << '\n';
}
