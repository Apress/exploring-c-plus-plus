/** @file artifact.hpp */
/** Listing 60-5. Defining an artifact Pimpl Wrapper Class */
#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <ctime>
#include <functional>
#include <string>

/// Forward declaration.
class artifact_impl;

/** Pimpl wrapper for artifacts. */
class artifact
{
public:
  /// Default constructor
  artifact();
  /// Construct an artifact with the given name
  /// @param name the artifact name
  artifact(std::string const& name);
  /// Copy constructor.
  /// Increments the reference count.
  artifact(artifact const& a);
  /// Destructor decrements the reference count.
  ~artifact();

  /// Assignment operator.
  /// Increments the refernece count
  artifact& operator=(artifact const& a);

  /// Returns the artifact name.
  std::string const& name()     const;
  /// Returns the modification time.
  std::time_t        mod_time() const;
  /// Expands variables in a string.
  /// @param str The string to expand
  /// @return a copy of the string after expanding variables.
  std::string        expand(std::string str) const;

  /// "Build" the artifact.
  void               build();
  /// Return the modification time of the artifact.
  /// In real life, this would probably check the file's modification time.
  std::time_t get_mod_time();

  /// Store a variable in the local map.
  /// @param name the variable name
  /// @param value the replacement value of the variable
  void store_variable(std::string const& name, std::string const& value);

private:
  artifact_impl* pimpl_;
};

/// Print an artifact by printing its name.
template<class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& out, artifact const& a)
{
  out << a.name();
  return out;
}

/// Compare two artifact objects for equality.
inline bool operator==(artifact const& a, artifact const& b)
{
  return a.name() == b.name();
}

/// Compare two artifact objects for inequality.
inline bool operator!=(artifact const& a, artifact const& b)
{
  return not(a == b);
}

namespace std {
  /// Specialize std::less<artifact> to permit the use of artifact as a key in sets and maps.
  template<>
  class less<artifact> : public std::binary_function<artifact, artifact, bool> {
  public:
    /// Compare artifacts by comparing their names.
    /// @param a
    /// @param b
    bool operator()(artifact const& a, artifact const& b)
    {
      return a.name() < b.name();
    }
  };
}

#endif // ARTIFACT_HPP_
