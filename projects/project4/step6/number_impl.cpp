#include <istream>
#include <ostream>
#include <sstream>

#include "calc_error.hpp"
#include "number_impl.hpp"

number_impl::~number_impl()
{}

void number_impl::add_ref()
{
  ++refcount_;
}

void number_impl::del_ref()
{
  --refcount_;
  if (refcount_ == 0)
    delete this;
}

void number_impl::save(std::ostream& stream)
const
{
  do_save(stream);
}

number_impl* number_impl::read_library(std::istream& stream)
{
  std::string type;
  if (not (stream >> type))
    throw calc_error("malformed library, missing number type");

  if (type == "void")
    return new number_void();

  if (type == "long") {
    long x;
    if (not (stream >> x))
      throw calc_error("malformed library, missing long value");
    return new number_long(x);
  }

  if (type == "double") {
    double x;
    if (not (stream >> x))
      throw calc_error("malformed library, missing double value");
    return new number_long(x);
  }

  throw calc_error("malformed library, unknown number type: " + type);
}

void number_impl::print(std::ostream& stream)
const
{
  stream << to_string();
}

std::string number_impl::to_string()
const
{
  return do_to_string();
}

number_impl* number_impl::promote(number_impl& rhs)
const
{
  return do_promote(rhs);
}

bool number_impl::equals(number_impl const& rhs)
const
{
  return do_equals(rhs);
}

bool number_impl::less(number_impl const& rhs)
const
{
  return do_less(rhs);
}

number_impl* number_impl::add(number_impl const& rhs)
{
  return do_add(rhs);
}

number_impl* number_impl::subtract(number_impl const& rhs)
{
  return do_subtract(rhs);
}

number_impl* number_impl::multiply(number_impl const& rhs)
{
  return do_multiply(rhs);
}

number_impl* number_impl::divide(number_impl const& rhs)
{
  return do_divide(rhs);
}

// Default is not to promote.
// The return value from the promote_to_*() functions is either
// a brand-new number_impl object, or this. In order to make the
// reference counts balance, when returning this, bump the reference count.
number_impl* number_impl::promote_to_void()
{
  add_ref();
  return this;
}

number_impl* number_impl::promote_to_long()
{
  add_ref();
  return this;
}

number_impl* number_impl::promote_to_rational()
{
  add_ref();
  return this;
}

number_impl* number_impl::promote_to_double()
{
  add_ref();
  return this;
}



std::string number_void::do_to_string()
const
{
  return std::string();
}

void number_void::do_save(std::ostream& stream)
const
{
  stream << "void ";
}

// void never equals anything, even another void
bool number_void::do_equals(number_impl const&)
const
{
  return false;
}

// void is never less than anything
bool number_void::do_less(number_impl const&)
const
{
  return false;
}

// void plus void equal void
number_impl* number_void::do_add(number_impl const&)
{
  add_ref();
  return this;
}

number_impl* number_void::do_subtract(number_impl const&)
{
  add_ref();
  return this;
}

number_impl* number_void::do_multiply(number_impl const&)
{
  add_ref();
  return this;
}

number_impl* number_void::do_divide(number_impl const&)
{
  add_ref();
  return this;
}

number_impl* number_void::do_promote(number_impl& rhs)
const
{
  return rhs.promote_to_void();
}



std::string number_long::do_to_string()
const
{
  std::ostringstream stream;
  stream << value();
  return stream.str();
}

void number_long::do_save(std::ostream& stream)
const
{
  stream << "long " << value() << ' ';
}

bool number_long::do_equals(number_impl const& rhs)
const
{
  return value() == dynamic_cast<number_long const&>(rhs).value();
}

bool number_long::do_less(number_impl const& rhs)
const
{
  return value() < dynamic_cast<number_long const&>(rhs).value();
}

number_impl* number_long::do_add(number_impl const& rhs)
{
  return new number_long(value_ + dynamic_cast<number_long const&>(rhs).value());
}

number_impl* number_long::do_subtract(number_impl const& rhs)
{
  return new number_long(value_ - dynamic_cast<number_long const&>(rhs).value());
}

number_impl* number_long::do_multiply(number_impl const& rhs)
{
  return new number_long(value_ * dynamic_cast<number_long const&>(rhs).value());
}

number_impl* number_long::do_divide(number_impl const& rhs)
{
  long right = dynamic_cast<number_long const&>(rhs).value();
  if (right == 0)
    throw calc_error("division by zero");
  return new number_rational(value_, right);
}

number_impl* number_long::do_promote(number_impl& rhs)
const
{
  return rhs.promote_to_long();
}

number_impl* number_long::promote_to_void()
{
  return new number_void();
}

number_impl* number_long::promote_to_rational()
{
  return new number_rational(value());
}

number_impl* number_long::promote_to_double()
{
  return new number_double(value());
}


std::string number_rational::do_to_string()
const
{
  std::ostringstream stream;
  stream << value();
  return stream.str();
}

void number_rational::do_save(std::ostream& stream)
const
{
  stream << "rational " << value() << ' ';
}

bool number_rational::do_equals(number_impl const& rhs)
const
{
  return value() == dynamic_cast<number_rational const&>(rhs).value();
}

bool number_rational::do_less(number_impl const& rhs)
const
{
  return value() < dynamic_cast<number_rational const&>(rhs).value();
}

number_impl* number_rational::do_add(number_impl const& rhs)
{
  rational<long> result = value_ + dynamic_cast<number_rational const&>(rhs).value();
  if (result.denominator() == 1)
    return new number_long(result.numerator());
  else
    return new number_rational(result);
}

number_impl* number_rational::do_subtract(number_impl const& rhs)
{
  rational<long> result = value_ - dynamic_cast<number_rational const&>(rhs).value();
  if (result.denominator() == 1)
    return new number_long(result.numerator());
  else
    return new number_rational(result);
}

number_impl* number_rational::do_multiply(number_impl const& rhs)
{
  rational<long> result = value_ * dynamic_cast<number_rational const&>(rhs).value();
  if (result.denominator() == 1)
    return new number_long(result.numerator());
  else
    return new number_rational(result);
}

number_impl* number_rational::do_divide(number_impl const& rhs)
{
  rational<long> right = dynamic_cast<number_rational const&>(rhs).value();
  if (right == 0L)
    throw calc_error("division by zero");
  rational<long> result = value_ / right;
  if (result.denominator() == 1)
    return new number_long(result.numerator());
  else
    return new number_rational(result);
}

number_impl* number_rational::do_promote(number_impl& rhs)
const
{
  return rhs.promote_to_rational();
}

number_impl* number_rational::promote_to_void()
{
  return new number_void();
}

number_impl* number_rational::promote_to_double()
{
  return new number_double(value().as<double>());
}



std::string number_double::do_to_string()
const
{
  std::ostringstream stream;
  stream << value();
  return stream.str();
}

void number_double::do_save(std::ostream& stream)
const
{
  stream << "double " << value() << ' ';
}

bool number_double::do_equals(number_impl const& rhs)
const
{
  return value() == dynamic_cast<number_double const&>(rhs).value();
}

bool number_double::do_less(number_impl const& rhs)
const
{
  return value() < dynamic_cast<number_double const&>(rhs).value();
}

number_impl* number_double::do_add(number_impl const& rhs)
{
  return new number_double(value_ + dynamic_cast<number_double const&>(rhs).value());
}

number_impl* number_double::do_subtract(number_impl const& rhs)
{
  return new number_double(value_ - dynamic_cast<number_double const&>(rhs).value());
}

number_impl* number_double::do_multiply(number_impl const& rhs)
{
  return new number_double(value_ * dynamic_cast<number_double const&>(rhs).value());
}

number_impl* number_double::do_divide(number_impl const& rhs)
{
  double right = dynamic_cast<number_double const&>(rhs).value();
  if (right == 0.0)
    throw calc_error("division by zero");
  return new number_double(value_ / right);
}

number_impl* number_double::do_promote(number_impl& rhs)
const
{
  return rhs.promote_to_double();
}

number_impl* number_double::promote_to_void()
{
  return new number_void();
}
