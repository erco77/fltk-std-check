SHELL=/bin/bash

# Override any of these with e.g. 'make CXX=clang'
CXX=g++
LINK=g++
ARC=arc

default: testapp

./lib:
	@echo Creating ./lib
	mkdir ./lib

TestLib.o: TestLib.cxx TestLib.H
	$(CXX) -c TestLib.cxx

lib/testlib.a: ./lib TestLib.o
	ar -rc lib/testlib.a TestLib.o

testapp: testapp.cxx lib/testlib.a
	$(CXX) testapp.cxx lib/testlib.a -o testapp
	
clean:
	- /bin/rm *.o
	if [[ -e lib/testlib.a ]]; then /bin/rm lib/testlib.a; fi
	if [[ -d lib           ]]; then /bin/rmdir lib;        fi

