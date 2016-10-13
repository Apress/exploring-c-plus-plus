/** @file list2903.cpp */
/** Listing 29-3. Testing the I/O Operators */
#include "list2903.code"

/// Tests for failbit only
bool iofailure(std::istream& in)
{
  return in.fail() and not in.bad();
}

int main()
{
  rational r(0);

  while (std::cin)
  {
    if (std::cin >> r)
      // Read succeeded, so no error state is set in the stream.
      std::cout << r << '\n';
    else if (iofailure(std::cin))
    {
      // Only failbit is set, meaning invalid input. Clear the error state, 
      // and then skip the rest of the input line.
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
  }

  if (std::cin.bad()) 
    std::cerr << "Unrecoverable input error\n";
}
