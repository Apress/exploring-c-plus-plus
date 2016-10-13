/** @file list3105.cpp */
/** Listing 31-5. Constructors for Class point */
struct point
{
  point()
  : x_(0.0), y_(0.0)
  {}
  point(double x, double y)
  : x_(x), y_(y)
  {}
  point(point const& pt)
  : x_(pt.x_), y_(pt.y_)
  {}
  double x_;
  double y_;
};
