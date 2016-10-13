/** @file list6007.cpp */
/** Listing 60-7. Defining the Artifact Implementation Class */
#ifndef ARTIFACT_IMPL_HPP_
#define ARTIFACT_IMPL_HPP_

#include <cstdlib>
#include <ctime>
#include <string>
#include "variables.hpp"

class artifact_impl
{
public:
  artifact_impl();
  artifact_impl(std::string const& name);  ~artifact_impl();

  void add_ref();
  void delete_ref();

  std::string const& name()     const { return name_; }
  std::time_t        mod_time() const { return mod_time_; }

  std::string        expand(std::string str) const;

  void               build();
  std::time_t        get_mod_time();
  void store_variable(std::string const& name, std::string const& value);
private:
  std::size_t ref_count_;
  std::string name_;
  std::time_t mod_time_;
  variable_map* variables_;
};

#endif // ARTIFACT_IMPL_HPP_
