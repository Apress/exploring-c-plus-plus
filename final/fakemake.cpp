/** @file fakemake.cpp */
/** Listing 60-9. Rewriting the Program to Use the New artifact Value Class */
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>

#include "artifact.hpp"
#include "depgraph.hpp"
#include "variables.hpp"

/// Store all artifacts here as they are read.
std::map<std::string, artifact> artifacts;

/// Lookup an artifact in the parse map.
artifact& lookup_artifact(std::string const& name)
{
  std::map<std::string, artifact>::iterator iter( artifacts.find(name) );
  if (iter != artifacts.end())
    return iter->second;
  else
  {
    artifacts.insert(std::make_pair(name, artifact(name)));
    return artifacts[name];
  }
}

/// Parse the fakemakefile, building a dependency graph.
/// @param[in] in The input stream
/// @param[out] graph The dependency graph to build
void parse_graph(std::istream& in, dependency_graph& graph)
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::string target_name, dependency_name;
    std::istringstream stream(line);
    if (stream >> target_name >> dependency_name)
    {
      artifact& target(lookup_artifact(expand(target_name)));
      std::string::size_type equal(dependency_name.find('='));
      if (equal == std::string::npos)
      {
        // It's a dependency specification
        artifact& dependency(lookup_artifact(target.expand(dependency_name)));
        graph.store_dependency(target, dependency);
      }
      else
        // It's a target-specific variable
        target.store_variable(dependency_name.substr(0, equal-1),
                              dependency_name.substr(equal+1));
    }
    else if (not target_name.empty())
    {
      std::string::size_type equal(target_name.find('='));
      if (equal == std::string::npos)
        // Input line has a target with no dependency,
        // so report an error.
        std::cerr << "malformed input: target, " << target_name <<
                     ", must be followed by a dependency name\n";
      else
        global_variables[target_name.substr(0, equal)] =
                                          target_name.substr(equal+1);
    }
    // else ignore blank lines
  }

  // Don't need the parse map any more.
  artifacts.clear();
}

int main()
{
  dependency_graph graph;

  parse_graph(std::cin, graph);

  try {
    // Get the sorted artifacts in reverse order.
    std::vector<artifact> sorted;
    graph.sort(std::back_inserter(sorted));

    // Then print the artifacts in the correct order.
    for (std::vector<artifact>::reverse_iterator it(sorted.rbegin());
         it != sorted.rend();
         ++it)
    {
      std::cout << it->name() << '\n';
    }
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
