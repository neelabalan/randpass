cmake_minimum_required(VERSION 2.8.12)
project(randpass)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(inc)
add_library(library INTERFACE)
target_include_directories(library INTERFACE inc/)

add_executable( randpass src/main.cpp)
target_link_libraries(randpass ${CONAN_LIBS})

