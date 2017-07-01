cmake_minimum_required(VERSION 3.6)
project(sort_compare)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Algorithms/RadixSort.cpp Algorithms/RadixSort.h Algorithms/SortAlgorithm.cpp Algorithms/SortAlgorithm.h Algorithms/ArrayUtils.cpp Algorithms/ArrayUtils.h Algorithms/InsertionSort.cpp Algorithms/InsertionSort.h)
add_library(sort_algorithms SHARED ${SOURCE_FILES})

set(MAIN_FILES Main.cpp)
add_executable(sortalgs ${MAIN_FILES})
target_link_libraries(sortalgs sort_algorithms)

