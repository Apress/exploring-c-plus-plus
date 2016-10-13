#include <iomanip>
#include <iterator>
#include <ostream>
#include <sstream>

#include "calc_error.hpp"
#include "node.hpp"
#include "node_impl.hpp"
#include "variables.hpp"

node_impl::node_impl()
: refcount_(1)
{}

node_impl::~node_impl()
{}

void node_impl::print(std::ostream& stream, int indent)
const
{
  print_node(stream, indent);
}

number node_impl::evaluate()
const
{
  return evaluate_node();
}

std::string node_impl::to_string()
const
{
  return evaluate_string();
}

void node_impl::add_ref()
{
  ++refcount_;
}

identifier_list const& node_impl::get_parameters()
const
{
  return evaluate_parameters();
}

void node_impl::del_ref()
{
  --refcount_;
  if (refcount_ == 0)
    delete this;
}

std::string node_impl::evaluate_string()
const
{
  std::ostringstream stream;
  stream << evaluate();
  return stream.str();
}

identifier_list const& node_impl::evaluate_parameters()
const
{
  static identifier_list const empty;
  return empty;
}

void node_impl::save(std::ostream& stream)
const
{
  save_node(stream);
}

/* Factory function to create node_impl objects from a saved library file. */
node_impl* node_impl::read_node(std::istream& stream)
{
  std::string type;
  if (not (stream >> type))
    return 0;
  if (type == "void")
    return new node_void(stream);
  if (type == "number")
    return new node_number(stream);
  if (type == "identifier")
    return new node_identifier(stream);
  if (type == "function")
    return new node_function(stream);
  if (type == "call")
    return new node_function_call(stream);
  if (type == "negate")
    return new node_negate(stream);
  if (type == "add")
    return new node_add(stream);
  if (type == "subtract")
    return new node_subtract(stream);
  if (type == "multiply")
    return new node_multiply(stream);
  if (type == "divide")
    return new node_divide(stream);

  throw calc_error("unknown node type: " + type);
}

node_void::node_void()
: node_impl()
{}

node_void::node_void(std::istream&)
: node_impl()
{}

void node_void::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "void\n";
}

number node_void::evaluate_node()
const
{
  return number();
}

std::string node_void::evaluate_string()
const
{
  return std::string();
}

void node_void::save_node(std::ostream& stream)
const
{
  stream << "void\n";
}

node_number::node_number(number value)
: node_impl(), value_(value)
{}

node_number::node_number(std::istream& stream)
: node_impl(), value_(stream)
{}

number node_number::value()
const
{
  return value_;
}

void node_number::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << value() << '\n';
}

number node_number::evaluate_node()
const
{
  return value();
}

void node_number::save_node(std::ostream& stream)
const
{
  stream << "number ";
  value().save(stream);
  stream << '\n';
}


node_identifier::node_identifier(std::string const& name)
: node_impl(), name_(name)
{}

node_identifier::node_identifier(std::istream& stream)
: node_impl()
{
  if (not (stream >> name_))
    throw calc_error("malformed library file, cannot read identifier");
}

std::string const& node_identifier::name()
const
{
  return name_;
}

void node_identifier::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "identifier " << name() << '\n';
}

number node_identifier::evaluate_node()
const
{
  return get_variable(name()).evaluate();
}

std::string node_identifier::evaluate_string()
const
{
  return name();
}

void node_identifier::save_node(std::ostream& stream)
const
{
  stream << "identifier " << name() << '\n';
}


node_function::node_function(identifier_list const& parameters, node definition)
: node_impl(), parameters_(parameters), definition_(definition)
{}

node_function::node_function(std::istream& stream)
: node_impl()
{
  std::size_t size;
  if (not (stream >> size))
    throw calc_error("malformed library file, cannot read function");
  parameters_.reserve(size);
  while (size-- != 0) {
    std::string parameter;
    if (not (stream >> parameter))
      throw calc_error("malformed library file, cannot read function parameter");
    parameters_.push_back(parameter);
  }
  definition_ = node(stream);
}

identifier_list const& node_function::parameters()
const
{
  return parameters_;
}

node node_function::definition()
const
{
  return definition_;
}

void print_identifier_list(std::ostream& stream, identifier_list const& identifiers)
{
  stream << '(';
  char const* sep = "";
  for (identifier_list::const_iterator id(identifiers.begin()); id != identifiers.end(); ++id) {
    stream << sep << *id;
    sep = ", ";
  }
  stream << ')';
}

void node_function::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "fun\n";
  print_identifier_list(stream, parameters());
  stream << '=';
  definition().print(stream, indent + 2);
}

number node_function::evaluate_node()
const
{
  return definition().evaluate();
}

identifier_list const& node_function::evaluate_parameters()
const
{
  return parameters();
}

void node_function::save_node(std::ostream& stream)
const
{
  stream << "function " << parameters().size() << ' ';
  std::copy(parameters().begin(), parameters().end(), std::ostream_iterator<std::string>(stream, " "));
  definition().save(stream);
}


node_function_call::node_function_call(std::string const& name, node_list const& arguments)
: node_impl(), name_(name), arguments_(arguments)
{}

node_function_call::node_function_call(std::istream& stream)
: node_impl()
{
  std::string name;
  if (not (stream >> name_))
    throw calc_error("malformed library file, cannot read function call name");
  std::size_t size;
  if (not (stream >> size))
    throw calc_error("malformed library file, cannot read function call");
  arguments_.reserve(size);
  while (size-- != 0) {
    arguments_.push_back(node(stream));
  }
}

std::string node_function_call::name()
const
{
  return name_;
}

node_list const& node_function_call::arguments()
const
{
  return arguments_;
}

void node_function_call::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << name() << "(\n";
  for (node_list::const_iterator first(arguments().begin()), arg(first); arg != arguments().end(); ++arg) {
    stream << std::setw(indent+1) << "" << "arg " << std::distance(first, arg) << ": ";
    arg->print(stream, indent + 2);
  }
  stream << std::setw(indent) << "" << ")\n";
}

number node_function_call::evaluate_node()
const
{
  // Create a local symbol table, assigning all the node values to the parameters.
  node function = get_function(name());
  identifier_list const& parameters( function.get_parameters() );
  if (parameters.size() != arguments().size())
    throw function_error(name(), parameters.size(), arguments().size());
  else
  {
    // Create a local symbol table by assigning the arguments to the function parameters.
    symbol_table locals;
    identifier_list::const_iterator parm(parameters.begin());
    for (node_list::const_iterator arg(arguments().begin()); arg != arguments().end(); ++arg, ++parm) {
      locals.insert(std::make_pair(*parm, *arg));
    }
    set_symbol_table syms(locals);
    return function.evaluate();
  }
}

void node_function_call::save_node(std::ostream& stream)
const
{
  stream << "call " << name() << ' ' << arguments().size() << ' ';
  for (node_list::const_iterator arg(arguments().begin()); arg != arguments().end(); ++arg)
    arg->save(stream);
}


node_unary::node_unary(node operand)
: node_impl(), operand_(operand)
{}

node_unary::node_unary(std::istream& stream)
: node_impl(), operand_(stream)
{}

node node_unary::operand()
const
{
  return operand_;
}

number node_unary::evaluate_operand()
const
{
  return operand().evaluate();
}

node_binary::node_binary(node left, node right)
: left_(left), right_(right)
{}

node_binary::node_binary(std::istream& stream)
: node_impl(), left_(stream), right_(stream)
{}

node node_binary::left()
const
{
  return left_;
}

node node_binary::right()
const
{
  return right_;
}

number node_binary::evaluate_left()
const
{
  return left().evaluate();
}

number node_binary::evaluate_right()
const
{
  return right().evaluate();
}


node_negate::node_negate(node operand)
: node_unary(operand)
{}

node_negate::node_negate(std::istream& stream)
: node_unary(stream)
{}

void node_negate::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "-\n";
  operand().print(stream, indent + 2);
}

number node_negate::evaluate_node()
const
{
  return -evaluate_operand();
}

void node_negate::save_node(std::ostream& stream)
const
{
  stream << "negate ";
  operand().save(stream);
}



node_add::node_add(node left, node right)
: node_binary(left, right)
{}

node_add::node_add(std::istream& stream)
: node_binary(stream)
{}

void node_add::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "+\n";
  left().print(stream, indent + 2);
  right().print(stream, indent + 2);
}

number node_add::evaluate_node()
const
{
  return evaluate_left() + evaluate_right();
}

void node_add::save_node(std::ostream& stream)
const
{
  stream << "add ";
  left().save(stream);
  right().save(stream);
}


node_subtract::node_subtract(node left, node right)
: node_binary(left, right)
{}

node_subtract::node_subtract(std::istream& stream)
: node_binary(stream)
{}

void node_subtract::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "-\n";
  left().print(stream, indent + 2);
  right().print(stream, indent + 2);
}

number node_subtract::evaluate_node()
const
{
  return evaluate_left() - evaluate_right();
}

void node_subtract::save_node(std::ostream& stream)
const
{
  stream << "subtract ";
  left().save(stream);
  right().save(stream);
}


node_multiply::node_multiply(node left, node right)
: node_binary(left, right)
{}

node_multiply::node_multiply(std::istream& stream)
: node_binary(stream)
{}

void node_multiply::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "*\n";
  left().print(stream, indent + 2);
  right().print(stream, indent + 2);
}

number node_multiply::evaluate_node()
const
{
  return evaluate_left() * evaluate_right();
}

void node_multiply::save_node(std::ostream& stream)
const
{
  stream << "multiply ";
  left().save(stream);
  right().save(stream);
}


node_divide::node_divide(node left, node right)
: node_binary(left, right)
{}

node_divide::node_divide(std::istream& stream)
: node_binary(stream)
{}

void node_divide::print_node(std::ostream& stream, int indent)
const
{
  stream << std::setw(indent) << "" << "/\n";
  left().print(stream, indent + 2);
  right().print(stream, indent + 2);
}

number node_divide::evaluate_node()
const
{
  return evaluate_left() / evaluate_right();
}

void node_divide::save_node(std::ostream& stream)
const
{
  stream << "divide ";
  left().save(stream);
  right().save(stream);
}
