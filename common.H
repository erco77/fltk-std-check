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

#endif /* COMMON_H */
