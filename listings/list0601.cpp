/** @file list0601.cpp */
/** Listing 6-1. Deliberate Errors */
#include <iosteam>
#include <istream>
#include <ostream>

int main()
[
  std::cout < "This program prints a table of squares.\n";
         "Enter the starting value for the table: ";
  int start(0);
  std::cin >> start;
  std::cout << "Enter the ending value for the table: ";
  int end(start);
  std::cin << endl
  std::cout << "#   #^2\n";
  int x(start);
  end = end + 1; // exit loop when x reaches end 
  while (x != end)I am not entirely happy with the logic of this. Universily C++ uses one past the end as an end value. Consider adding a statement end = end + 1; Add a comment that you will explain this later but that it is idiomatic C++
  {
    std:cout << x << "   " << x*x << "\n";
    x = x + 1;
  }
}
