#include "TestLib.H"

// Populate the class with test data
void TestLib::test_populate(void) {
  name("John Doe");
  value_clear();
  value_add(1);
  value_add(2);
  value_add(3);
  value_add(4);
}

// Show the class's contents
void TestLib::show(const char *prefix) const {
  fprintf(stderr, "%sTestLib: name=<%s>\n", prefix, name_.c_str());
  for (int i=0; i<value_size(); i++) {
    fprintf(stderr, "%sTestLib: value(%d) = <%d>\n", prefix, i, value(i));
  }
}
