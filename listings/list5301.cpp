/** @file list5301.cpp */
/** Listing 53-1. Reading and Writing Currency Using the Money Facets */
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>

/// Read monetary values from an input stream.
/// Construct a reader, passing an input stream to its constructor. Call the
/// function call operator every time you want to read a value.
class money_reader
{
public:
  money_reader(std::istream& in);
  bool operator()(std::string& digits);
private:
  std::istream& in_;
  std::money_get<char> const& get_;
};

/// Write monetary values to an output stream.
/// Construct a writer, passing an output stream to its constructor. Call the
/// function call operator every time you want to write a value.
class money_writer
{
public:
  money_writer(std::ostream& out);
  bool operator()(std::string const& digits);
private:
  std::ostream& out_;
  std::money_put<char> const& put_;
};

money_reader::money_reader(std::istream& in)
: in_(in), get_(std::use_facet<std::money_get<char> >(in.getloc()))
{}

bool money_reader::operator()(std::string& digits)
{
  // The sentry flushes prompts prior to reading, and skips leading white space.
  std::istream::sentry sentry(in_);
  if (not in_)
    return in_;

  std::ios_base::iostate error(in_.rdstate());
  get_.get(std::istreambuf_iterator<char>(in_), std::istreambuf_iterator<char>(),
           false, in_, error, digits);
  in_.setstate(error);
  return in_;
}

money_writer::money_writer(std::ostream& out)
: out_(out), put_(std::use_facet<std::money_put<char> >(out.getloc()))
{}

bool money_writer::operator()(std::string const& digits)
{
  // The sentry flushes prompts prior to writing, and flushes the buffer
  // if the user has set buffering to unit buffering.
  std::ostream::sentry sentry(out_);
  if (not out_)
    return out_;

  std::ios_base::iostate error(out_.rdstate());
  put_.put(std::ostreambuf_iterator<char>(out_), false, out_, error, digits);
  out_.setstate(error);
  return out_;
}

int main()
{
  std::locale native("");
  std::cin.imbue(native);
  std::cout.imbue(native);

  std::cin >> std::noshowbase;  // currency symbol is optional for input
  std::cout << std::showbase;   // always write the currency symbol for output

  money_reader read(std::cin);
  money_writer write(std::cout);
  std::string digits;
  while (read(digits))
  {
    write(digits);
    std::cout << '\n';
  }
  if (not std::cin.eof())
    std::cout << "Invalid input.\n";
}
