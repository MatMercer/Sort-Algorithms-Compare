cmake_minimum_required(VERSION 3.6)
project(sort_compare)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SortAlgorithms/RadixSort.cpp SortAlgorithms/RadixSort.h SortAlgorithms/SortAlgorithm.cpp SortAlgorithms/SortAlgorithm.h SortAlgorithms/ArrayUtils.cpp SortAlgorithms/ArrayUtils.h SortAlgorithms/InsertionSort.cpp SortAlgorithms/InsertionSort.h SortAlgorithms/BubbleSort.cpp SortAlgorithms/BubbleSort.h)
add_library(sort_algorithms SHARED ${SOURCE_FILES})

set(MAIN_FILES Main.cpp)
add_executable(sortalgs ${MAIN_FILES})
target_link_libraries(sortalgs sort_algorithms)

