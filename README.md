# fltk-std-check
Small test suite to exercise std use in a library/app situation

    NOTE: 
    Currently only linux supported, and initial tests only
    used g++ (9.x.x) and clang (10.x.x).

## Files
                _
    TestLib.cxx  |_ The "single class" library's .cxx
    TestLib.H   _|  and .H files with std instances.
    common.H      - Handles FL_EXPORT and compiler version checks
    testapp.cxx   - The test application
    Makefile      - Has these targets:
    bin/get_compiler_version
                  - python script that creates FL_COMPILER_XXX macros

## Make targets

    clean       - clean everything
    default     - builds lib and testapp
    lib         - builds just the lib (lib/testlib.a file)
    testapp     - builds just the testapp (and checks lib vs app compiler versions)
    compiler_version - updates the FL_COMPILER_XXX macros

## Normal Build
By default the Makefile builds with g++ on linux, and should
show no warnings to build the lib and testapp this way:

    # Build the lib AND testapp
    make clean; make

Running testapp exercises the simple std::string and std::vector instances, which we can expand on later when we know what we want to exercise to check for problems.

## Separate Library/App Build
If the local linux machine has both g++ and clang++-10 installed,
we can test the #warning mechanism by building the lib with g++
and the testapp with clang.

The following should trigger a #warning directive when building the "testapp":

    # Make the library only (using g++)
    make clean; make CXX=g++ lib

    # Make the testapp, (using clang++-10):
    make CXX=clang++-10 testapp

The build for 'testapp' will post a #warning, assuming the output
of 'clang++10 --version' and 'g++ --version' differ.

