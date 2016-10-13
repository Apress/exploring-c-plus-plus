/** @file lpk.cpp */
/** Dervied from Listing 54-8, but converted to Liters-per-kilometer. */

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
      ++linenum;
      std::string::size_type comment(line.find('#'));
      if (comment != std::string::npos)
         line.erase(comment);
      std::istringstream input(line);
      double fuel;
      if (input >> odometer)
      {
         char check;
         if (not (input >> fuel))
         {
            std::cerr << "Missing fuel consumption on line " << linenum << '\n';
            error = true;
         }
         else if (input >> check)
         {
            std::cerr << "Extra text on line " << linenum << '\n';
            error = true;
         }
         else if (odometer != prev_odometer)
         {
            double distance(odometer - prev_odometer);
            std::cout << fuel * 100 / distance << '\n';
            total_fuel += fuel;
            prev_odometer = odometer;
         }
      }
   }
   if (odometer != 0)
   {
      std::cout << "Net LP100K=" << total_fuel * 100 / odometer;
      if (error)
         std::cout << " (estimated, due to input error)";
      std::cout << '\n';
   }
}
