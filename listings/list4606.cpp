/** @file list4606.cpp */
/** Listing 46-6. Implementing the find Algorithm */
template<class InputIterator, class T>
InputIterator find(InputIterator start, InputIterator end, T value)
{
  for ( ; start != end; ++start)
    if (*start == value)
      return start;
  return end;
}
