/** @file list5403.cpp */
/** Listing 54-3. Computing Miles-Per-Gallon */
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
   double fuel, odometer;
   double prev_odometer(0.0);
   double total_fuel(0.0);
   while (std::cin >> odometer >> fuel)
   {
      if (fuel != 0)
      {
         double distance(odometer - prev_odometer);
         std::cout << distance / fuel << '\n';
         total_fuel += fuel;
         prev_odometer = odometer;
      }
   }
   if (total_fuel != 0)
      std::cout << "Net MPG=" << odometer / total_fuel << '\n';
}
