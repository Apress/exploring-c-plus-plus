/** @file list6207.cpp */
/** Listing 62-7. Program to Test the language Class */
#include <iostream>
#include <istream>
#include <ostream>

#include "language.hpp"

int main()
{
   language lang;
   while (true) {
      std::cout << "What is your favorite programming language? ";
      std::cin >> lang;
      if (std::cin.good())
      {
         if (lang == language::high)
            lang = language::low;
         else
            ++lang;
         std::cout << "Have you considered " << lang << "?\n";
         return 0;
      }
      if (std::cin.fail())
      {
         std::cout << "Unknown language. Please choose one of the following:\n";
         for (language x(language::low); x != language::high; ++x)
            std::cout << x << ' ';
         std::cout << language(language::high) << '\n';
         std::cin.clear();
      }
   }
}
