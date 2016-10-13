/** @file list1404.cpp */
/** Listing 14-4. Searching for a Word in a Map */
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>

int main()
{
  using namespace std;

  map<string, int> counts;
  string word;

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (cin >> word)
    ++counts[word];

  map<string,int>::iterator the(counts.find("the"));
  if (the == counts.end())
    cout << "\"the\": not found\n";
  else if (the->second == 1)
    cout << "\"the\": occurs " << the->second << " time\n";
  else
    cout << "\"the\": occurs " << the->second << " times\n";
}
