#include <string>
#include <vector>
#include <stdio.h>
#include "common.H"     // Fl_Export, g++ vers checks, etc

class FL_EXPORT TestLib {
  // private data
  std::string name_;
  std::vector<int> value_arr_;
public:
  // public data
  //    (none at this time)

  // ctor/dtor
  TestLib() { fprintf(stderr, "--- TestLib CTOR\n"); }
  ~TestLib() { fprintf(stderr, "--- TestLib DTOR\n"); }

  // set
  void name(const char *s) { name_ = s; }
  void name(std::string& s) { name_ = s; }
  void value_clear() { value_arr_.clear(); }
  void value_append(int i) { value_arr_.push_back(i); }

  // get
  const char* name(void) const { return name_.c_str(); }
  std::string name_std(void) const { return name_; }         // copy
  int value(int i) const { return value_arr_[i]; }
  int value_size(void) const { return value_arr_.size(); }
  std::vector<int> values_std(void) const { return value_arr_; }    // copy

  // misc
  void show(const char *prefix="") const;
  void test_populate(void);
};
