/** @file list6008.cpp */
/** Listing 60-8. The artifact_impl.cpp Source File */
artifact_impl::artifact_impl()
: ref_count_(1), name_(), mod_time_(static_cast<time_t>(-1)), variables_(0)
{}

artifact_impl::artifact_impl(std::string const& name)
: ref_count_(1), name_(name), mod_time_(get_mod_time()), variables_(0)
{}

artifact_impl::~artifact_impl()
{
   delete variables_;
}

void artifact_impl::add_ref()
{
   ++ref_count_;
}

void artifact_impl::delete_ref()
{
   --ref_count_;
   if (ref_count_ == 0)
     delete this;
}

std::string const& artifact_impl::name()
const
{
   return name_;
}

std::time_t artifact_impl::mod_time()
const
{
   return mod_time_;
}

std::string artifact_impl::expand(std::string str)
const
{
   return ::expand(str, variables_);
}

void artifact_impl::build()
{}

std::time_t artifact_impl::get_mod_time()
{
    // Real programs should get this information from the
    // operating system. This program returns the current time.
    return std::time(0);
}

void artifact_impl::store_variable(std::string const& name,
                                   std::string const& value)
{
   if (variables_ == 0)
      variables_ = new variable_map;
   (*variables_)[name] = value;
}
