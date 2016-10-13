/** @file list3205.cpp */
/** Listing 32-5. Adding the const Modifier to print */
  /// Print this record to @p out.
  void print(std::ostream& out, int threshold)
  const
  {
    out << std::setw(6) << height_
        << std::setw(7) << weight_
        << std::setw(3) << sex_
        << std::setw(6) << bmi_;
    if (bmi_ >= threshold)
      out << '*';
    else
      out << ' ';
    out << ' ' << name_ << '\n';
  }
