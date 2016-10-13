/** @file list3913.cpp */
/** Listing 39-13. The Original point.hpp File */
#ifndef POINT_HPP_
#define POINT_HPP_
class point
{
public:
  point() : x_(0), y_(0) {}
  point(int x, int y) : x_(x), y_(y) {}
  int x() const { return x_; }
  int y() const { return y_; }
private:
  int y_, x_;
};
#endif // POINT_HPP_
