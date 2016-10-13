/** @file list6311.cpp */
/** Listing 63-11. The thing Class with All of Its Mix-ins. */
class thing: public assignment_mixin<thing>,
    public comparison_mixin<thing>,
    public equality_mixin<thing>
{
public:
   thing() : value_() {}
   thing(std::string const& s) : value_(s) {}
   void swap(thing& other) { value_.swap(other.value_); }
   std::string const& str() const { return value_; }
private:
   std::string value_;
};
bool operator==(thing const& lhs, thing const& rhs)
{
  return lhs.str() == rhs.str();
}

bool operator<( thing const& lhs, thing const& rhs)
{
  return lhs.str() < rhs.str();
}

int main()
{
   thing a, b("xyz"), c(b);
   assert(a == a);
   assert(a != b);
   assert(a <= b);
   assert(b >= c);
   assert(c > a);
   c = a;
   assert(a == c);
   assert(a != b);
   assert(c <= b);
}
