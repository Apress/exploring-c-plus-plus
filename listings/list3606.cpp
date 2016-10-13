/** @file list3606.cpp */
/** Listing 36-6. Adding a print Member Function to the movie Class */
class movie : public work
{
public:
  movie() : runtime_(0) {}
  movie(std::string const& id, std::string const& title, int runtime)
  : work(id, title), runtime_(runtime)
  {}
  int runtime() const { return runtime_; }
  virtual void print(std::ostream& out) const
  {
    out << title() << " (" << runtime() << " min)";
  }
private:
  int runtime_; ///< running length in minutes
};
