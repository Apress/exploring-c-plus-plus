/** @file list4906.cpp */
/** Listing 49-6. Specializing fixed for N == 0 */
template<class T>
class fixed<T, 0>
{
public:
    typedef T value_type;
    static const T places = 0;
    static const T places10 = 1;
    fixed() : value_() {}
    fixed(T const& integer, T const&) : value_(integer) {}
    fixed& operator=(fixed const& rhs) { value_ = rhs; }
    fixed& operator+=(fixed const& rhs) { value_ += rhs; }
    fixed& operator*=(fixed const& rhs) { value_ *= rhs; }
    // and so on...
private:
    T value_; // no need for scaling
};
