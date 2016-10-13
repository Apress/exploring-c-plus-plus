/** @file list6309.cpp */
/** Listing 63-9. Using mix-in Class Template */
class thing: public assignment_mixin<thing> {
public:
   thing() : value_() {}
   thing(std::string const& s) : value_(s) {}
   void swap(thing& other) { value_.swap(other.value_); }
private:
   std::string value_;
};

int main()
{
   thing one;
   thing two("two");
   one = two;
}
