/** @file list4207.cpp */
/** Listing 42-7. You Can’t erase with a const_iterator */
#include <algorithm>
#include "data.hpp"

// Find the answer in data.
intvector::const_iterator find_answer(intvector const& data)
{
  return std::find(data.begin(), data.end(), 42);
}

int main()
{
  intvector data;
  read_data(data);
  // find the answer, and erase all elements from that point onward
  data.erase(find_answer(data), data.end());
}
