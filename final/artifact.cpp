/** @file artifact.cpp */
/** Listing 60-6. Implementing the artifact Class */
#include "artifact.hpp"
#include "artifact_impl.hpp"

artifact::artifact() : pimpl_(new artifact_impl()) {}

artifact::artifact(std::string const& name)
: pimpl_(new artifact_impl(name))
{}

artifact::artifact(artifact const& a)
: pimpl_(a.pimpl_)
{
   pimpl_->add_ref();
}

artifact::~artifact()
{
   pimpl_->delete_ref();
}

artifact& artifact::operator=(artifact const& a)
{
   a.pimpl_->add_ref();
   pimpl_->delete_ref();
   pimpl_ = a.pimpl_;
   return *this;
}

std::string const& artifact::name()
const
{
   return pimpl_->name();
}

std::time_t artifact::mod_time()
const
{
   return pimpl_->mod_time();
}

std::string artifact::expand(std::string str)
const
{
   return pimpl_->expand(str);
}

void artifact::build()
{
   pimpl_->build();
}

std::time_t artifact::get_mod_time()
{
   return pimpl_->get_mod_time();
}

void artifact::store_variable(std::string const& name, std::string const& value)
{
    pimpl_->store_variable(name, value);
}
