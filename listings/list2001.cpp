/** @file list2001.cpp */
/** Listing 20-1. Function Arguments and Parameters */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

void modify(int x)
{
  x = 10;
}

int triple(int x)
{
  return 3 * x;
}

void print_vector(std::vector<int> v)
{
  std::cout << "{ ";
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

void add(std::vector<int> v, int a)
{
  for (std::vector<int>::iterator i(v.begin()); i != v.end(); ++i)
    *i = *i + a;
}

int main()
{
  int a(42);
  modify(a);
  std::cout << "a=" << a << '\n';

  int b(triple(14));
  std::cout << "b=" << b << '\n';

  std::vector<int> data;
  data.push_back(10);
  data.push_back(20);
  data.push_back(30);
  data.push_back(40);

  print_vector(data);
  add(data, 42);
  print_vector(data);
}
