/** @file list5406.cpp */
/** Listing 54-6. Parsing Comments in the Miles-Per-Gallon Data File */
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
      char comment;
      if (input >> comment and comment != '#')
      {
         input.unget();
         double fuel;
         if (input >> odometer)
         {
            if (not (input >> fuel))
            {
               std::cerr << "Missing fuel consumption on line " << linenum << '\n';
               error = true;
            }
            else if (fuel != 0)
            {
               double distance(odometer - prev_odometer);
               std::cout << distance / fuel << '\n';
               total_fuel += fuel;
               prev_odometer = odometer;
            }
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
