/** @file list6502.cpp */
/** Listing 65-2. Hypothetical Arbitrary-Size Integer Class */
namespace bigmath
{
  class integer
  {
  public:
    integer() : negative_(false), digits_() {}
    integer(long value);
    void abs() { negative_ = false; }
  private:
    bool negative_;
    std::vector<unsigned int> digits_;
  };

  integer abs(integer const& i)
  {
    integer result(i);
    result.abs();
    return result;
  }
}
