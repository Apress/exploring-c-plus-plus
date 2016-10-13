/** @file depgraph.cpp */
/** Listing 56-5. Storing Pointers in the Dependency Graph */

#include "depgraph.hpp"

void dependency_graph::store_dependency(artifact const& target, artifact const& dependency)
{
  graph_[dependency].insert(target);
  graph_[target];
}
