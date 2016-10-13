/** @file list3805.cpp */
/** Listing 38-5. Generating Unique Identification Numbers */
int generate_id()
{
  static int counter(0);
  ++counter;
  return counter;
}
