/** @file list4605.cpp */
/** Listing 46-5. One Way to Implement the copy Algorithm */
template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator start, InputIterator end, OutputIterator result)
{
  for ( ; start != end; ++start, ++result)
    *result = *start;
  return result;
}
