/** @file list5603.cpp */
/** Listing 56-3. New Definition of an Artifact */
#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <ctime>
#include <string>

class artifact
{
public:
  artifact() : name_(), mod_time_(static_cast<time_t>(-1)) {}
  artifact(std::string const& name)
  : name_(name), mod_time_(get_mod_time())
  {}

  std::string const& name()     const { return name_; }
  std::time_t        mod_time() const { return mod_time_; }

  /// Build a target.
  /// After completing the actions (not yet implemented),
  /// update the modification time.
  void build();

  /// Look up the modification time of the artifact.
  /// Return static_cast<time_t>(-1) if the artifact does not
  /// exist (and therefore must be built) or if the time cannot
  /// be obtained for any other reason.
  /// Also see boost::file_system::last_write_time.
  std::time_t get_mod_time()
  {
    // Real programs should get this information from the
    // operating system. This program returns the current time.
    return std::time(0);
  }
private:
  std::string name_;
  std::time_t mod_time_;
};

#endif // ARTIFACT_HPP_
