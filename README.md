# fltk-std-check
Small test suite to exercise std use in a library/app situation

    NOTE: 
    Currently only linux supported, and initial tests only
    used g++ (9.x.x) and clang (10.x.x).

By default the Makefile builds with g++ on linux, and should
show no warnings this way:

    # Build the lib AND testapp
    make clean; make

If the local linux machine has both g++ and clang++-10 installed,
we can test the #warning mechanism by building the lib with g++
and the testapp with clang:

    # Make the library only (using g++)
    make clean; make CXX=g++ lib

    # Make the testapp, (using clang++-10):
    make CXX=clang++-10 testapp

The build for 'testapp' will post a #warning, assuming the output
of 'clang++10 --version' and 'g++ --version' differ.

