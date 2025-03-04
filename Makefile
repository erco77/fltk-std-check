SHELL=/bin/bash

# Override any of these with e.g. 'make CXX=clang'
CXX=g++
LINK=g++
ARC=arc

default: testapp

lib: lib/testlib.a

compiler_version:
	python bin/get_compiler_version -command "$(CXX) --version" > library_compiler_version.H

TestLib.o: TestLib.cxx TestLib.H
	$(CXX) -c TestLib.cxx

lib/testlib.a: TestLib.o
	if [[ ! -d lib ]]; then mkdir lib; fi
	ar -rc lib/testlib.a TestLib.o

testapp: testapp.cxx lib/testlib.a
	$(CXX) testapp.cxx lib/testlib.a -o testapp
	
clean:
	- /bin/rm *.o
	if [[ -e lib/testlib.a ]]; then /bin/rm lib/testlib.a; fi
	if [[ -d lib           ]]; then /bin/rmdir lib;        fi

