/** @file list5604.cpp */
/** Listing 56-4. Second Draft, Adding Modification Times to Artifacts */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "artifact.hpp"
#include "topological_sort.hpp"

typedef std::size_t artifact_index;

class dependency_graph
{
public:
  typedef std::map<artifact_index, std::set<artifact_index> > graph_type;

  void store_dependency(artifact_index target, artifact_index dependency)
  {
    graph_[dependency].insert(target);
  }

  graph_type const& graph() const { return graph_; }

  template<class OutIter>
  void sort(OutIter sorted)
  const
  {
    topological_sort(graph_, sorted);
  }

private:
  graph_type graph_;
};

std::vector<artifact> artifacts;
artifact_index lookup_artifact(std::string const& name)
{
  for (artifact_index i(0); i != artifacts.size(); ++i)
    if (artifacts[i].name() == name)
      return i;
  // Artifact not found, so add it to the end.
  artifacts.push_back(artifact(name));
  return artifacts.size() - 1;
}

int main()
{
  dependency_graph graph;

  std::string line;
  while (std::getline(std::cin, line))
  {
    std::string target_name, dependency_name;
    std::istringstream stream(line);
    if (stream >> target_name >> dependency_name)
    {
      artifact_index target(lookup_artifact(target_name));
      artifact_index dependency(lookup_artifact(dependency_name));
      graph.store_dependency(target, dependency);
    }
    else if (not target_name.empty())
      // Input line has a target with no dependency,
      // so report an error.
      std::cerr << "malformed input: target, " << target_name <<
                   ", must be followed by a dependency name\n";
    // else ignore blank lines
  }

  try {
    // Get the sorted artifact indices in reverse order.
    std::vector<artifact_index> sorted;
    graph.sort(std::back_inserter(sorted));
    // Then print the artifacts in the correct order.
    for (std::vector<artifact_index>::reverse_iterator it(sorted.rbegin());
         it != sorted.rend();
         ++it)
    {
      std::cout << artifacts.at(*it).name() << '\n';
    }
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
