/** @file list6107.cpp */
/** Listing 61-7. Using Shift Operators to Define the Formatting Fields */
int boolalpha_pos = 0;
int showbase_pos  = 1;
int showpoint_pos = 2;
int showpos_pos   = 3;
int skipws_pos    = 4;
int adjust_pos    = 5;
int adjust_size   = 2;
int float_pos     = 7;
int float_size    = 2;

fmtflags boolalpha   = 1 << boolalpha_pos;
fmtflags showbase    = 1 << showbase_pos;
fmtflags showpos     = 1 << showpos_pos;
fmtflags showpoint   = 1 << showpoint_pos;
fmtflags skipws      = 1 << showpoint_pos;
fmtflags adjustfield = 3 << adjust_pos;
fmtflags floatfield  = 3 << float_pos;

fmtflags left     = 0 << adjust_pos;
fmtflags right    = 1 << adjust_pos;
fmtflags internal = 2 << adjust_pos;

fmtflags fixed      = 1 << float_pos;
fmtflags scientific = 2 << float_pos;
