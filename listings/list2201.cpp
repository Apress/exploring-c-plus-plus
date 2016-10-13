/** @file list2201.cpp */
/** Listing 22-1. Printing Vectors by Using Overloaded Functions */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

void print(int i)
{
  std::cout << i;
}

void print(int i, int width)
{
  std::cout.width(width);
  std::cout << i;
}

void print(std::vector<int> const& vec, int width,
std::string const& prefix, std::string const& separator, std::string const& postfix)
{
  bool print_prefix(true);
  for (std::vector<int>::const_iterator v(vec.begin()); v != vec.end(); ++v)
  {
    if (print_prefix)
      std::cout << prefix;
    else
      std::cout << separator;
    print_prefix = false;
    std::cout.width(width);
    std::cout << *v;
  }
  if (print_prefix)
    std::cout << prefix;
  std::cout << postfix;
}

void print(std::vector<int> const& vec,
std::string const& prefix, std::string const& separator, std::string const& postfix)
{
  print(vec, 0, prefix, separator, postfix);
}

int main()
{
  std::vector<int> data;
  data.insert(data.begin(),
              std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

  std::cout << "columnar data:\n";
  print(data, 10, "", "", "\n");
  std::cout << "row data:\n";
  print(data, "{", ", ", "}\n");
}
