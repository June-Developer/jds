# CMakeList.txt : CMake project for jds, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (jds "jds.cpp" "jds.h" "jds/jiterator.cpp" "jds/jiterator.h" "jds/jlist.cpp" "jds/jlist.h" "jds/jqueue.cpp" "jds/jqueue.h" "jds/jstack.cpp" "jds/jstack.h")

# TODO: Add tests and install targets if needed.
