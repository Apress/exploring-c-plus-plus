/** @file list5405.cpp */
/** Listing 54-5. Rewriting the Miles-Per-Gallon Program to Parse a String Stream */
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

int main()
{
   double prev_odometer(0.0), odometer(0.0);
   double total_fuel(0.0);
   std::string line;
   int linenum(0);
   bool error(false);
   while (std::getline(std::cin, line))
   {
      std::istringstream input(line);
      ++linenum;
      double fuel;
      if (input >> odometer)
      {
         if (not (input >> fuel))
         {
            std::cerr << "Missing fuel consumption on line " << linenum << '\n';
            error = true;
         }         else if (fuel != 0)
         {
            double distance(odometer - prev_odometer);
            std::cout << distance / fuel << '\n';
            total_fuel += fuel;
            prev_odometer = odometer;
         }
      }
   }
   if (total_fuel != 0)
   {
      std::cout << "Net MPG=" << odometer / total_fuel;
      if (error)
         std::cout << " (estimated, due to input error)";
      std::cout << '\n';
   }
}
