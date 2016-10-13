/** @file list3607.cpp */
/** Listing 36-7. Defining work as an Abstract Class. */
class work
{
public:
  work() : id_(), title_() {}
  work(std::string const& id, std::string const& title) : id_(id), title_(title) {}
  virtual ~work() {}
  std::string const& id()    const { return id_; }
  std::string const& title() const { return title_; }
  virtual void print(std::ostream& out) const = 0;
private:
  std::string id_;
  std::string title_;
};
