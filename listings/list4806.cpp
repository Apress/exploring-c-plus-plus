/** @file list4806.cpp */
/** Listing 48-6. Specializing numeric_limits for the rational Class */
namespace std {
template<>
class numeric_limits<rational>
{
public:
  static bool const is_specialized = true;
  static rational min() throw() { return rational(numeric_limits<int>::min()); }
  static rational max() throw() { return rational(numeric_limits<int>::max()); }
  static int const digits = 2 * numeric_limits<int>::digits;
  static int const digits10 = numeric_limits<int>::digits10;
  static bool const is_signed = true;
  static bool const is_integer = false;
  static bool const is_exact = true;
  static int const radix = 2;
  static bool const is_bounded = true;
  static bool const is_modulo = false;
  static bool const traps = std::numeric_limits<int>::traps;

  static rational epsilon() throw()
  { return rational(1, numeric_limits<int>::max()-1); }
  static rational round_error() throw()
  { return rational(1, numeric_limits<int>::max()); }
  static float_round_style const round_style = round_to_nearest;

  // The following are meaningful only for floating-point types.
  static int const min_exponent = 0;
  static int const min_exponent10 = 0;
  static int const max_exponent = 0;
  static int const max_exponent10 = 0;
  static bool const has_infinity = false;
  static bool const has_quiet_NaN = false;
  static bool const has_signaling_NaN = false;
  static float_denorm_style const has_denorm = denorm_absent;
  static bool const has_denorm_loss = false;
  // The following are meant only for floating-point types, but you have
  // to define them, anyway, even for nonfloating-point types. The values
  // they return do not have to be meaningful.
  static rational infinity() throw() { return rational(); }
  static rational quiet_NaN() throw() { return rational(); }
  static rational signaling_NaN() throw() { return rational(); }
  static rational denorm_min() throw() { return rational(); }
  static bool const is_iec559 = false;
  static bool const tinyness_before = false;
};

}
