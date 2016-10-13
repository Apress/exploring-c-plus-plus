/** @file list6103.cpp */
/** .funcListing 61-3. A Simple Implementation of the unsetf Member Function */
void unsetf(fmtflags f)
{
   flags_ = flags_ & ~f;
}
