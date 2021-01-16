cmake_minimum_required(VERSION 3.6)
project(sort_compare)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/SortAlgorithms/*.cpp ${PROJECT_SOURCE_DIR}/src/SortAlgorithms/*.h)

add_library(sort_algorithms SHARED ${SRC_FILES})
set_target_properties(sort_algorithms PROPERTIES LINKER_LANGUAGE CXX)

set(MAIN_FILES src/Main.cpp)
add_executable(sortalgs ${MAIN_FILES})
set_target_properties(sortalgs PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(sortalgs sort_algorithms)
