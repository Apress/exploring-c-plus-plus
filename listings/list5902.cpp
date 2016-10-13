/** @file list5902.cpp */
/** Listing 59-2. Echoing Command-Line Arguments */
#include <iostream>
#include <ostream>

int main(int argc, char* argv[])
{
  char const* separator("");
  while (--argc != 0)
  {
    std::cout << separator << *++argv;
    separator = " ";
  }
}
