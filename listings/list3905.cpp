/** @file list3905.cpp */
/** Listing 39-5. The #include File for the generate_id Class */
/// Class for generating a unique ID number.
class generate_id
{
public:
  generate_id() : counter_(0) {}
  long next();
private:
  short counter_;
  static short prefix_;
  static long int const max_counter_ = 32767;
};
