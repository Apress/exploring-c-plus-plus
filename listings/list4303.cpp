/** @file list4303.cpp */
/** Listing 43-3. Forcing a string to Throw Exceptions */
#include <exception>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

int main()
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    try
    {
      line.at(10) = ' ';                               // can throw out_of_range
      for (std::string::size_type size(line.size());
           size < line.max_size();
           size = size * 2)
      {
        line.resize(size);                             // can throw bad_alloc
      }
      line.resize(line.max_size());                    // can throw bad_alloc
      line.push_back('x');                             // throws length_error
      std::cout << "okay\n";
    }
    catch (std::out_of_range const& ex)
    {
       std::cout << ex.what() << '\n';
       std::cout << "string index (10) out of range.\n";
    }
    catch (std::length_error const& ex)
    {
      std::cout << ex.what() << '\n';
      std::cout << "maximum string length (" << line.max_size() << ") exceeded.\n";
    }
    catch (std::exception const& ex)
    {
      std::cout << "other exception: " << ex.what() << '\n';
    }
    catch (...)
    {
      std::cout << "Unknown exception type. Program terminating.\n";
      std::terminate();
    }
  }
}
