/** @file list6205.cpp */
/** Listing 62-5. The language.cpp File Initializes the Language Data Structures */
#include "language.hpp"

namespace {
   class initializer {
   public:
      initializer() { language::initialize(); }
   };
   initializer init;
}
