/** @file list1302.cpp */
/** Listing 13-2. Copying Integers from a Named File to a Named File */
#include <cstdio>
#include <fstream>
#include <istream>
#include <ostream>

int main()
{
  std::ifstream in("list1302.in");
  if (not in)
    std::perror("list1302.in");
  else
  {
    std::ofstream out("list1302.out");
    if (not out)
      std::perror("list1302.out");
    else
    {
      int x(0);
      while (in >> x)
        out << x << '\n';
      out.close();
      in.close();
    }
  }
}
