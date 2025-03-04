#ifndef COMMON_H
#define COMMON_H

/*
 * (nabbed from Fl_Export.H)
 * The following is used when building DLLs under Windows
 * and when building .so's under unix/linux.
 */
#  if defined(FL_DLL)
#    ifdef FL_LIBRARY
#      define FL_EXPORT __declspec(dllexport)
#    else
#      define FL_EXPORT __declspec(dllimport)
#    endif /* FL_LIBRARY */
#  elif __GNUC__ >= 4
#    define FL_EXPORT __attribute__ ((visibility ("default")))
#  else
#    define FL_EXPORT
#  endif /* FL_DLL */

// Get library compiler version
#include "library_compiler_version.H"

// GNU compiler version check
#ifdef __GNUC__
  #if __GNUC__ != FL_COMPILER_MAJOR
    #warning Different major compiler versions: See <some_url>
  #elif __GNUC_MINOR__ != FL_COMPILER_MINOR
    #warning Different minor compiler versions: See <some_url>
  #endif /* GNU CHECK */
#endif /* __GNUC__ */

#endif /* COMMON_H */
