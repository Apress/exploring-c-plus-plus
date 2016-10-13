#ifndef NUMBER_IMPL_HPP_
#define NUMBER_IMPL_HPP_

#include <iosfwd>
#include <string>

#include "rational.hpp"

class number_impl
{
public:
  number_impl() : refcount_(1) {}
  virtual ~number_impl();

  /** Print in a human-readable form. */
  void print(std::ostream& stream) const;
  /** Convert to a string. */
  std::string to_string() const;

  /** Save a number to a library file. */
  void save(std::ostream& stream) const;
  /** Read the number type from a library file, then create the proper kind of number. */
  static number_impl* read_library(std::istream& stream);

  bool equals(number_impl const& rhs) const;
  bool less(number_impl const& rhs) const;

  number_impl* add(number_impl const& rhs);
  number_impl* subtract(number_impl const& rhs);
  number_impl* multiply(number_impl const& rhs);
  number_impl* divide(number_impl const& rhs);

  void add_ref();
  void del_ref();

  /** Promote @p rhs to match the type of @c this number.
   * This function uses double-dispatch, so this number
   * calls a virtual promote_to_*() function that notifies
   * @p rhs of the desired type. If the desired type is "larger"
   * than the type of @p rhs, the promote_to_*() function
   * returns a new number_impl of the desired type. Otherwise,
   * the function returns @p rhs.
   *
   * @param rhs The right-hand operand of an arithmetic expression.
   */
  number_impl* promote(number_impl& rhs) const;

  virtual number_impl* promote_to_void();
  virtual number_impl* promote_to_long();
  virtual number_impl* promote_to_rational();
  virtual number_impl* promote_to_double();

private:
  number_impl(number_impl const& n); ///< not implemented
  number_impl& operator=(number_impl const& n); ///< not implemented

  virtual std::string do_to_string() const = 0;
  virtual void do_save(std::ostream& stream) const = 0;

  virtual bool do_equals(number_impl const& rhs) const = 0;
  virtual bool do_less(number_impl const& rhs) const = 0;

  virtual number_impl* do_add(number_impl const& rhs) = 0;
  virtual number_impl* do_subtract(number_impl const& rhs) = 0;
  virtual number_impl* do_multiply(number_impl const& rhs) = 0;
  virtual number_impl* do_divide(number_impl const& rhs) = 0;

  virtual number_impl* do_promote(number_impl& rhs) const = 0;

  std::size_t refcount_;
};

/** Represent a number without a type.
 * A void number cannot be converted into any other type,
 * but any type can be converted to void.
 */
class number_void : public number_impl {
public:
  number_void() : number_impl() {}
private:
  virtual std::string do_to_string() const;
  virtual void do_save(std::ostream& stream) const;
  virtual bool do_equals(number_impl const& rhs) const;
  virtual bool do_less(number_impl const& rhs) const;
  virtual number_impl* do_add(number_impl const& rhs);
  virtual number_impl* do_subtract(number_impl const& rhs);
  virtual number_impl* do_multiply(number_impl const& rhs);
  virtual number_impl* do_divide(number_impl const& rhs);
  virtual number_impl* do_promote(number_impl& rhs) const;
};

/** Represent an integer.
 * For the greatest range, always use @c long to represent integers.
 */
class number_long : public number_impl {
public:
  number_long(long value) : number_impl(), value_(value) {}
  long value() const { return value_; }
  virtual number_impl* promote_to_void();
  virtual number_impl* promote_to_rational();
  virtual number_impl* promote_to_double();
private:
  virtual std::string do_to_string() const;
  virtual void do_save(std::ostream& stream) const;
  virtual bool do_equals(number_impl const& rhs) const;
  virtual bool do_less(number_impl const& rhs) const;
  virtual number_impl* do_add(number_impl const& rhs);
  virtual number_impl* do_subtract(number_impl const& rhs);
  virtual number_impl* do_multiply(number_impl const& rhs);
  virtual number_impl* do_divide(number_impl const& rhs);
  virtual number_impl* do_promote(number_impl& rhs) const;

  long value_;
};

/** Represent a rational number.
 * For the greatest range, always use @c long to represent the numerator and denominator.
 */
class number_rational: public number_impl {
public:
  number_rational(rational<long> value) : number_impl(), value_(value) {}
  number_rational(long num) : number_impl(), value_(num) {}
  number_rational(long num, long den) : number_impl(), value_(num, den) {}
  rational<long> value() const { return value_; }
  virtual number_impl* promote_to_void();
  virtual number_impl* promote_to_double();
private:
  virtual std::string do_to_string() const;
  virtual void do_save(std::ostream& stream) const;
  virtual bool do_equals(number_impl const& rhs) const;
  virtual bool do_less(number_impl const& rhs) const;
  virtual number_impl* do_add(number_impl const& rhs);
  virtual number_impl* do_subtract(number_impl const& rhs);
  virtual number_impl* do_multiply(number_impl const& rhs);
  virtual number_impl* do_divide(number_impl const& rhs);
  virtual number_impl* do_promote(number_impl& rhs) const;

  rational<long> value_;
};

/** Represent a floating-point value.
 * Always use @c double to represent floating-point values.
 */
class number_double : public number_impl {
public:
  number_double(double value) : number_impl(), value_(value) {}
  double value() const { return value_; }
  virtual number_impl* promote_to_void();
private:
  virtual std::string do_to_string() const;
  virtual void do_save(std::ostream& stream) const;
  virtual bool do_equals(number_impl const& rhs) const;
  virtual bool do_less(number_impl const& rhs) const;
  virtual number_impl* do_add(number_impl const& rhs);
  virtual number_impl* do_subtract(number_impl const& rhs);
  virtual number_impl* do_multiply(number_impl const& rhs);
  virtual number_impl* do_divide(number_impl const& rhs);
  virtual number_impl* do_promote(number_impl& rhs) const;

  double  value_;
};

#endif
