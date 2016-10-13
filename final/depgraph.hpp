/** @file depgraph.hpp */
/** Listing 56-5. Storing Pointers in the Dependency Graph */

#include <set>
#include <map>

#include "artifact.hpp"
#include "topological_sort.hpp"

/** Represent a dependency as a map of sets.
 * The map key is the dependency. The value is a set of targets
 * that have the key as a dependency.
 */
class dependency_graph
{
public:
  /// The graph type.
  typedef std::map<artifact, std::set<artifact> > graph_type;

  /// Record a dependency in the graph.
  /// @param target The target of the dependency relationship
  /// @param dependency The target depends on this @p dependency
  void store_dependency(artifact const& target, artifact const& dependency);

  /// Return the graph.
  graph_type const& graph() const { return graph_; }

  /// Sort the dependency graph using topological sort.
  /// Generate a list of dependencies starting with targets that have
  /// no dependencies.
  /// @param[out] sorted Store the sorted dependencies here
  template<class OutIter>
  void sort(OutIter sorted)
  const
  {
    topological_sort(graph_, sorted);
  }

private:
  graph_type graph_;
};
