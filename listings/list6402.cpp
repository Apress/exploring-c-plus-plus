/** @file list6402.cpp */
/** Listing 64-2. Example Program to Use the my_advance Function */
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <vector>

#include "advance.hpp" // the code from Listing 64-1

int main()
{
   std::vector<int> vector;
   vector.push_back(10);
   vector.push_back(20);
   vector.push_back(30);
   vector.push_back(40);
   std::list<int> list(vector.begin(), vector.end());
   std::vector<int>::iterator vector_iterator(vector.begin());
   std::list<int>::iterator list_iterator(list.begin());
   std::ifstream file("advance.hpp");
   std::istream_iterator<std::string> input_iterator(file);

   my_advance(input_iterator, 2);
   my_advance(list_iterator, 2);
   my_advance(vector_iterator, 2);
}
