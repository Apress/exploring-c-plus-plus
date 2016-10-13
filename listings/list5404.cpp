/** @file list5404.cpp */
/** Listing 54-4.Computing Liters-Per-Kilometer */
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
      double distance(odometer - prev_odometer);
      if (distance != 0)
      {
         std::cout << fuel / distance << '\n';
         total_fuel += fuel;
         prev_odometer = odometer;
      }
   }
   if (odometer != 0)
      std::cout << "Net LPK=" << total_fuel / odometer << '\n';
}
