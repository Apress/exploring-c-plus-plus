/** @file list6304.cpp */
/** Listing 63-4. The HashableString Class */
class HashableString : public Hashable
{
public:
   HashableString() : string_() {}
   ~HashableString();
   unsigned long hash() const;
   bool equalTo(Hashable const&) const;

   // Implement the entire interface of std::string ...
private:
   std::string string_;
};
