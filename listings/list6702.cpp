/** @file list6702.cpp */
/** Listing 67-2. Simple Implementation of the power10 Class Template */
template<unsigned N>
struct power10
{
  enum t { value = 10 * power10<N – 1>::value };
};

template<>
struct power10<0>
{
  enum t { value = 1 };
};
