/** @file list4607.cpp */
/** Listing 46-7. The std::min Algorithm */
template<class T>
T min(T a, T b)
{
  if (a < b)
    return a;
  else
    return b;
}
