SHELL=/bin/bash

# Override any of these with 'make -D FOO=bar'
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
	- /bin/rmdir lib

