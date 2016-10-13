/** @file list4006.cpp */
/** Listing 40-6. Extracting BMI Values */
#include <algorithm>
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>
#include <string>
#include <vector>

#include "vital_stats.hpp"

int main()
{
  std::cout.imbue(std::locale(""));
  std::cin.imbue(std::locale(""));

  std::vector<vital_stats> data;

  std::cout << "Enter name, height (in cm),"
               " and weight (in kg) for each person:\n";
  vital_stats stats;
  while (stats.read(std::cin, data.size()+1))
    data.push_back(stats);

  // Copy only the BMI values to bmi_data.
  std::vector<int> bmi_data(data.size());
  std::transform(data.begin(), data.end(), bmi_data.begin(),
                 std::mem_fun_ref(&vital_stats::bmi));

  // Do stuff with bmi_data.
#include "list4006.code"
}
