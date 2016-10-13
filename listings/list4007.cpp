/** @file list4007.cpp */
/** Listing 40-7. The Functor Class Created by mem_fun_ref */
class mem_fun_ref_class
{
public:
  int operator()(vital_stats const& obj)
  const
  {
    return obj.bmi();
  }
};
