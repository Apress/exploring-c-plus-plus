/** @file
 * Use the randomint class to print random numbers to the standard output
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>

#include "randomint.hpp"

int main(int argc, char** argv)
{
  if (argc < 3) {
    std::cerr << "usage: " << argv[0] << " LOW HIGH [COUNT]\n";
    return EXIT_FAILURE;
  }

#ifdef __LINUX__
  // On GNU/Linux, read the /dev/urandom file to get random bits.
  std::ifstream in("/dev/urandom", std::ios_base::in | std::ios_base::binary);
  if (in) {
    unsigned int seed;
    in.read(reinterpret_cast<char*>(&seed), sizeof(seed));
  }
  else
#endif
  // On Linux systems where /dev/urandom cannot be read, or on other
  // systems, use the current time as the seed. This is weak for any
  // true need for random integers, but adequate for instructional purposes.
  std::srand(std::time(0));

  int low = std::atoi(argv[1]);
  int high = std::atoi(argv[2]);
  int count = argc < 4 ? 1 : std::atoi(argv[3]);

  randomint rng(low, high);
  for (int i = 0; i < count; ++i) {
    std::cout << rng() << '\n';
  }
}
