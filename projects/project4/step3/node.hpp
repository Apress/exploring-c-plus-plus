#ifndef NODE_HPP_
#define NODE_HPP_

#include <iosfwd>
#include <string>

/// Forward declaration of the node implementation base class.
class node_impl;

/** Wrapper class for all parse-tree nodes.
 * The actual parse tree nodes derive from node_impl.
 * This class uses the pimpl idiom to make it easier
 * to work with node objects.
 */
class node {
public:
  /** Construct a node of type void. */
  node();
  /** Construct a numeric node.
   * @param number The number
   */
  node(double number);
  /** Construct an identifier node.
   * @param identifier The name of the identifier
   */
  node(std::string const& identifier);
  /** Construct an assignment node.
   * @param identifier The name of the variable that is the target of the assignment
   * @param number the node for the expression to assign to the variable
   */
  node(node identifier, node number);
  /** Construct a unary operator node.
   * @param op The operator character, e.g., @c '-'
   * @param operand The operand node
   */
  node(char op, node operand);
  /** Construct a binary operator node.
   * @param left The left-hand parse-tree
   * @param op The operator character, e.g., @c '*'
   * @param right The right-hand operand
   */
  node(node left, char op, node right);
  /** Copy constructor.
   * Increments the reference count.
   * @param n The node to copy
   */
  node(node const& n);
  /** Destructor.
   * Decrements the reference count.
   */
  ~node();

  /** Copy assignment operator decrements the reference count.
   * @param n the source of the assignment
   */
  node& operator=(node const& n);

  /** Print a tree.
   * For debugging, print a visual representation of the parse tree.
   * Each level increments the @p indent to make the tree structure evident.
   * @param stream The output stream
   * @param indent The indentation.
   */
  void print(std::ostream& stream, int indent = 0) const;
  /** Evaluate a parse tree.
   * Evaluate and tree and return the result.
   */
  double evaluate() const;
  /** Return a string representation.
   * For an identifier node, return the identifier.
   * For all other nodes, return a string representation of the evaluated value.
   */
  std::string to_string() const;

private:
  /// Factory function to make the binary operator nodes.
  static node_impl* make_binary_operator(node, char, node);

  node_impl* pimpl_;
};

#endif
