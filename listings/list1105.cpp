/** @file list1105.cpp */
/** Listing 11-5. Comparing Vectors */
#include <iostream>
#include <ostream>
#include <vector>

int main()
{
   std::vector<int> a, b;
   a.push_back(10);
   a.push_back(20);
   a.push_back(30);
   b.push_back(10);
   b.push_back(20);
   b.push_back(30);
   if (a != b) std::cout << "wrong: a != b\n";
   if (a < b)  std::cout << "wrong: a < b\n";
   if (a > b)  std::cout << "wrong: a > b\n";
   if (a == b) std::cout << "okay: a == b\n";
   if (a >= b) std::cout << "okay: a >= b\n";
   if (a <= b) std::cout << "okay: a <= b\n";

   a.push_back(40);
   if (a != b) std::cout << "okay: a != b\n";
   if (a < b)  std::cout << "wrong: a < b\n";
   if (a > b)  std::cout << "okay: a > b\n";
   if (a == b) std::cout << "wrong: a == b\n";
   if (a >= b) std::cout << "okay: a >= b\n";
   if (a <= b) std::cout << "wrong: a <= b\n";

   b.push_back(42);
   if (a != b) std::cout << "okay: a != b\n";
   if (a < b)  std::cout << "okay: a < b\n";
   if (a > b)  std::cout << "wrong: a > b\n";
   if (a == b) std::cout << "wrong: a == b\n";
   if (a >= b) std::cout << "wrong: a >= b\n";
   if (a <= b) std::cout << "okay: a <= b\n";
}
