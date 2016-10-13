#include <stdexcept>

#include "node.hpp"
#include "node_impl.hpp"

node_impl* node::make_binary_operator(node left, char op, node right)
{
  if (op == '+')
    return new node_add(left, right);
  else if (op == '-')
    return new node_subtract(left, right);
  else if (op == '*')
    return new node_multiply(left, right);
  else if (op == '/')
    return new node_divide(left, right);
  else
    throw std::logic_error("fatal error in make_binary_opreator: unknown operator: " + op);
}

node::node()
: pimpl_(new node_void())
{}

node::node(node const& n)
: pimpl_(n.pimpl_)
{
  pimpl_->add_ref();
}

node::node(double number)
: pimpl_(new node_number(number))
{}

node::node(std::string const& identifier)
  : pimpl_(new node_identifier(identifier))
  {}

node::node(char op, node operand)
: pimpl_(new node_negate(operand))
{}

node::node(node left, char op, node right)
: pimpl_(make_binary_operator(left, op, right))
{}

node::node(identifier_list const& parameters, node definition)
: pimpl_(new node_function(parameters, definition))
{}

node::node(std::string const& name, node_list const& arguments)
: pimpl_(new node_function_call(name, arguments))
{}

node::~node()
{
  pimpl_->del_ref();
}

node& node::operator=(node const& n)
{
  n.pimpl_->add_ref();
  pimpl_->del_ref();
  pimpl_ = n.pimpl_;

  return *this;
}

void node::print(std::ostream& stream, int indent)
const
{
  pimpl_->print(stream, indent);
}

double node::evaluate()
const
{
  return pimpl_->evaluate();
}

std::string node::to_string()
const
{
  return pimpl_->to_string();
}

identifier_list const& node::get_parameters()
const
{
  return pimpl_->get_parameters();
}
