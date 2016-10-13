/** @file list4111.cpp */
/** Listing 41-11. Erasing Elements from a Vector */
#include <algorithm>
#include "data.hpp"
#include "intrange.hpp"

class outofrange
{
public:
  outofrange(int low, int high) : range_(low, high) {}
  bool operator()(int test) const { return not range_(test); }
private:
  intrange range_;
};

int main()
{
  intvector data;
  read_data(data);
  data.erase(std::remove(data.begin(), data.end(), 0), data.end());
  intvector copy;
  std::remove_copy_if(data.begin(), data.end(), std::back_inserter(copy),
                      outofrange(24, 42));
  std::sort(copy.begin(), copy.end());
  copy.erase(std::unique(copy.begin(), copy.end()), copy.end());
  write_data(copy);
}
