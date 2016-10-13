/** @file list5705.cpp */
/** Listing 57-5. Adding Variable Storage and Lookup to the artifact Class */
#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <ctime>
#include <string>

#include "variables.hpp"

class artifact
{
public:
  artifact()
  : name_(), mod_time_(static_cast<time_t>(-1)), variables_(0)
  {}
  artifact(std::string const& name)
  : name_(name), mod_time_(get_mod_time()), variables_(0)
  {}
  ~artifact()
  {
    delete variables_;
  }

  std::string const& name()     const { return name_; }
  std::time_t        mod_time() const { return mod_time_; }
  std::string        expand(std::string str) const
  {
    return ::expand(str, variables_);
  }

  /// Build a target.
  /// After completing the actions (not yet implemented),
  /// update the modification time.
  void build();

  /// Look up the modification time of the artifact.
  /// Return static_cast<time_t>(-1) if the artifact does not
  /// exist (and therefore must be built) or if the time cannot
  /// be obtained for any other reason.
  std::time_t get_mod_time()
  {
    // Real programs should get this information from the
    // operating system. This program returns the current time.
    return std::time(0);
  }

  /// Store a per-target variable.
  void store_variable(std::string const& name, std::string const& value)
  {
    if (variables_ == 0)
      variables_ = new variable_map;
    (*variables_)[name] = value;
  }
private:
  std::string name_;
  std::time_t mod_time_;
  variable_map* variables_;
};

#endif // ARTIFACT_HPP_
