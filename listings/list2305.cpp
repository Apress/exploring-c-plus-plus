/** @file list2305.cpp */
/** Listing 23-5. Overloading Prefers Type Promotion over Type Conversion */
#include <iostream>
#include <ostream>

// print is overloaded for signed char, short, int and long
void print(signed char b)
{
  std::cout << "print(signed char = " << static_cast<int>(b) << ")\n";
}

void print(short s)
{
  std::cout << "print(short = " << s << ")\n";
}

void print(int i)
{
  std::cout << "print(int = " << i << ")\n";
}

void print(long l)
{
  std::cout << "print(long = " << l << ")\n";
}

// guess is overloaded for bool, int, and long
void guess(bool b)
{
  std::cout << "guess(bool = " << b << ")\n";
}

void guess(int i)
{
  std::cout << "guess(int = " << i << ")\n";
}

void guess(long l)
{
  std::cout << "guess(long = " << l << ")\n";
}

// error is overloaded for bool and long
void error(bool b)
{
  std::cout << "error(bool = " << b << ")\n";
}

void error(long l)
{
  std::cout << "error(long = " << l << ")\n";
}

int main()
{
  signed char byte(10);
  short shrt(20);
  int i(30);
  long lng(40);

  print(byte);
  print(shrt);
  print(i);
  print(lng);

  guess(byte);
  guess(shrt);
  guess(i);
  guess(lng);

  error(byte); // expected error
  error(shrt); // expected error
  error(i);    // expected error
  error(lng);
}
