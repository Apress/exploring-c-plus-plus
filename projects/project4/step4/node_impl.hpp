#ifndef NODE_IMPL_HPP_
#define NODE_IMPL_HPP_

#include <cstdlib>
#include <string>

#include "node.hpp"

/** Base class for all parse tree nodes.
 * The node classes all derive from node_impl.
 * Each derived class overrides print_node(), for debugging
 * and evalute_node() to evaluate the node. A few classes
 * also override evaluate_string(), but most classes can inherit
 * the node_impl::evaluate_string implementation, which prints
 * the result of calling evaluate().
 *
 * This class primarily manages the reference count.
 */
class node_impl {
public:
  node_impl();
  virtual ~node_impl();

  void print(std::ostream& stream, int indent) const;

  double evaluate() const;

  std::string to_string() const;

  identifier_list const& get_parameters() const;

  void add_ref();
  void del_ref();

private:
  node_impl(node_impl const& n); ///< not implemented
  node_impl& operator=(node_impl const& n); ///< not implemented

  virtual void print_node(std::ostream& stream, int indent) const = 0;
  virtual double evaluate_node() const = 0;
  virtual std::string evaluate_string() const;
  virtual identifier_list const& evaluate_parameters() const;

  std::size_t refcount_;
};

/** Void data type.
 * Currently used only for the node default constructor.
 */
class node_void : public node_impl {
public:
  node_void();
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
  virtual std::string evaluate_string() const;
};

/** Number data type.
 * Used for numeric literals.
 */
class node_number : public node_impl {
public:
  node_number(double value);
  double value() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;

  double value_;
};

/** Identifier data type.
 * Used for variable references.
 */
class node_identifier : public node_impl {
public:
  node_identifier(std::string const& name);
  std::string const& name() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
  virtual std::string evaluate_string() const;

  std::string name_;
};

/** Function definition.
 * A function has parameters and a definition.
 */
class node_function : public node_impl {
public:
  node_function(identifier_list const& parameters, node definition);
  identifier_list const& parameters() const;
  node definition() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
  virtual identifier_list const& evaluate_parameters() const;

  identifier_list parameters_;
  node definition_;
};

/** Function call. */
class node_function_call : public node_impl {
public:
  node_function_call(std::string const& name, node_list const& arguments);
  std::string name() const;
  node_list const& arguments() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;

  std::string name_;
  node_list arguments_;
};

/** Abstract base class for unary operators. */
class node_unary : public node_impl {
public:
  node_unary(node operand);
  node operand()  const;
protected:
  double evaluate_operand() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const = 0;
  virtual double evaluate_node() const = 0;

  node operand_;
};

/** Abstract base class for binary operators. */
class node_binary : public node_impl {
public:
  node_binary(node left, node right);
  node left()  const;
  node right() const;
protected:
  double evaluate_left() const;
  double evaluate_right() const;
private:
  virtual void print_node(std::ostream& stream, int indent) const = 0;
  virtual double evaluate_node() const = 0;

  node left_;
  node right_;
};

/** Unary negation. */
class node_negate : public node_unary {
public:
  node_negate(node operand);
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
};

/** Addition. */
class node_add : public node_binary {
public:
  node_add(node left, node right);
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
};

/** Subtraction. */
class node_subtract : public node_binary {
public:
  node_subtract(node left, node right);
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
};

/** Multiplication. */
class node_multiply : public node_binary {
public:
  node_multiply(node left, node right);
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
};

/** Division. */
class node_divide : public node_binary {
public:
  node_divide(node left, node right);
private:
  virtual void print_node(std::ostream& stream, int indent) const;
  virtual double evaluate_node() const;
};

#endif
