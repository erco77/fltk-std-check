#include <string>
#include <vector>
#include "TestLib.H"

int main(int argc, char *argv[]) {
  TestLib tl;
  tl.test_populate();

  // Show
  fprintf(stderr, "testapp: TestLib::show(): START\n");
  tl.show("testapp: ");
  fprintf(stderr, "testapp: TestLib::show(): END\n");

  // Access
  int i;
  std::string name = tl.name();
  fprintf(stderr, "testapp: name = <%s>\n", name.c_str());
  for (i=0; i<tl.value_size(); i++) {
    fprintf(stderr, "testapp: value(%d) = <%d>\n", i, tl.value(i));
  }

  // vector copy: read
  std::vector<int> vals = tl.values_std();   // copy of array
  for (i=0; i<vals.size(); i++) {
    fprintf(stderr, "testapp: vals[%d] = <%d>\n", i, vals[i]);
  }

  // vector copy: write
  // TBD

  return 0;
}
