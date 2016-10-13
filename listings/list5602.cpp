/** @file list5602.cpp */
/** Listing 56-2. First Draft of the Pseudo-Make Program */
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

#include "topological_sort.hpp"

typedef std::string artifact; ///< A target, dependency, or both

class dependency_graph
{
public:
  typedef std::map<artifact, std::set<artifact> > graph_type;

  void store_dependency(artifact target, artifact dependency)
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

int main()
{
  dependency_graph graph;

  std::string line;
  while (std::getline(std::cin, line))
  {
    std::string target, dependency;
    std::istringstream stream(line);
    if (stream >> target >> dependency)
      graph.store_dependency(target, dependency);
    else if (not target.empty())
      // Input line has a target with no dependency,
      // so report an error.
      std::cerr << "malformed input: target, " << target <<
                   ", must be followed by a dependency name\n";
    // else ignore blank lines
  }

  try {
    // Get the artifacts in reverse order.
    std::vector<artifact> sorted;
    graph.sort(std::back_inserter(sorted));
    // Then print them in the correct order.
    std::copy(sorted.rbegin(), sorted.rend(),
              std::ostream_iterator<artifact>(std::cout, "\n"));
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
