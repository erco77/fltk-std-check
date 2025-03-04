cmake_minimum_required(VERSION 3.15)
project(fltk-std-check)

add_library(testlib STATIC common.H TestLib.H TestLib.cxx)
target_include_directories(testlib PUBLIC ${CMAKE_BINARY_DIR})

add_library(testlib-shared SHARED common.H TestLib.H TestLib.cxx)
target_include_directories(testlib-shared PUBLIC ${CMAKE_BINARY_DIR})

add_executable(testapp testapp.cxx)
target_link_libraries(testapp PRIVATE testlib)

add_executable(testapp-shared testapp.cxx)
target_link_libraries(testapp-shared PRIVATE testlib-shared)

# This can be added to a .cmake file
function(generate_library_compiler_version)
    set(FLTK_COMPILER_NAME ${CMAKE_CXX_COMPILER_ID})

    string(REGEX MATCHALL "[0-9]+" version_parts ${CMAKE_CXX_COMPILER_VERSION})
    list(LENGTH version_parts length)

    list(GET version_parts 0 FLTK_COMPILER_VERSION_MAJOR)
    list(GET version_parts 1 FLTK_COMPILER_VERSION_MINOR)
    list(GET version_parts 2 FLTK_COMPILER_VERSION_PATCH)

    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/library_compiler_version.H.in" "${CMAKE_BINARY_DIR}/library_compiler_version.H" @ONLY)
endfunction(generate_library_compiler_version)

generate_library_compiler_version()

#### our different compiler targets
add_custom_target(testapp_gcc
    DEPENDS testlib
    COMMAND g++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND g++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and statically linking testapp.cxx with g++"
)

add_custom_target(testapp_clang
    DEPENDS testlib
    COMMAND clang++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND clang++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and statically linking testapp.cxx with clang++"
)

add_custom_target(testapp_libcxx
    DEPENDS testlib
    COMMAND clang++
        -stdlib=libc++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND clang++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and statically linking testapp.cxx with clang++ and libcxx"
)

add_custom_target(testapp_gcc_shared
    DEPENDS testlib-shared
    COMMAND g++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND g++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib-shared>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and dynamically linking testapp.cxx with g++"
)

add_custom_target(testapp_clang_shared
    DEPENDS testlib-shared
    COMMAND clang++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND clang++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib-shared>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and dynamically linking testapp.cxx with clang++"
)

add_custom_target(testapp_libcxx_shared
    DEPENDS testlib-shared
    COMMAND clang++
        -stdlib=libc++
        -I${CMAKE_BINARY_DIR}
        -c ${CMAKE_CURRENT_SOURCE_DIR}/testapp.cxx
        -o ${CMAKE_BINARY_DIR}/testapp.o
    COMMAND clang++
        ${CMAKE_BINARY_DIR}/testapp.o
        $<TARGET_FILE:testlib-shared>
        -o ${CMAKE_BINARY_DIR}/testapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling and dynamically linking testapp.cxx with clang++ and libc++"
)
