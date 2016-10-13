/** @file list6005.cpp */
/** Listing 60-5. Defining an artifact Pimpl Wrapper Class */
#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <ctime>
#include <string>

class artifact_impl;

class artifact
{
public:
  artifact();
  artifact(std::string const& name);
  artifact(artifact const& a);
  ~artifact();

  artifact& operator=(artifact const& a);

  std::string const& name()     const;
  std::time_t        mod_time() const;
  std::string        expand(std::string str) const;

  void build();
  std::time_t get_mod_time();

  void store_variable(std::string const& name, std::string const& value);

private:
  artifact_impl* pimpl_;
};

bool operator<(artifact const& a, artifact const& b)
{
  return a.name() < b.name();
}

#endif // ARTIFACT_HPP_
