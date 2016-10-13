/** @file list6106.cpp */
/** Listing 61-6. Two-Argument Form of the setf Function */
void setf(fmtflags flags_to_set, fmtflags field)
{
   flags_ &= ~field;
   flags_ |= flags_to_set;
}
