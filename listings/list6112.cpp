/** @file list6112.cpp */
/** Listing 61-12. Declaring Formatting Flags with Bitfields */
struct fmtflags {
   bool skipws_f :         1;
   bool boolalpha_f:       1;
   bool showpoint_f:       1;
   bool showbase_f:        1;
   bool showpos_f:         1;
   unsigned adjustfield_f: 2;
   unsigned floatfield_f:  2;

   static unsigned const left     = 0;
   static unsigned const right    = 1;
   static unsigned const internal = 2;

   static unsigned const fixed      = 1;
   static unsigned const scientific = 2;
};
