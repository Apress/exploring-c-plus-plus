/** @file list6303.cpp */
/** Listing 63-3. The Hashable Interface in C++ */
class Hashable
{
public:
   virtual ~Hashable() = 0;
   virtual unsigned long hash() const = 0;
   virtual bool equalTo(Hashable const&) const = 0;
};
