/** @file artifact_impl.hpp */
/** Listing 60-7. Defining the Artifact Implementation Class */
#ifndef ARTIFACT_IMPL_HPP_
#define ARTIFACT_IMPL_HPP_

#include <cstdlib>
#include <ctime>
#include <string>

#include "variables.hpp"

/** Implementation of the artifact pimpl.
 * This is where the real work takes place, plus managing the reference count.
 */
class artifact_impl
{
public:
  /// Default constructor
  artifact_impl();
  /// Constructor with an artifact name.
  artifact_impl(std::string const& name);
  /// Destructor.
  ~artifact_impl();

  /// Increment the reference count.
  void add_ref();
  /// Decrement the reference count.
  /// When the count reaches zero, destroy this object.
  void delete_ref();

  /// Return the artifact name.
  std::string const& name()     const;
  /// Return the modification time.
  std::time_t        mod_time() const;

  /// Expand variable names in @p str.
  /// Each occurrence of @c $(NAME) is replaced by the value of
  /// the variable @c NAME in @p str. Look in the local variable
  /// map first, then in the global map.
  /// @param str the string to expand
  std::string        expand(std::string str) const;

  /// "Build" the artifact.
  void               build();
  /// Return the modification time of the artifact.
  /// In real life, this would probably check the file's modification time.
  std::time_t        get_mod_time();
  /// Store a variable in the local map.
  /// @param name the variable name
  /// @param value the replacement value of the variable
  void store_variable(std::string const& name, std::string const& value);
private:
  std::size_t ref_count_;
  std::string name_;
  std::time_t mod_time_;
  variable_map* variables_;
};

#endif // ARTIFACT_IMPL_HPP_
