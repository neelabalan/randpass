cmake_minimum_required(VERSION 2.8.12)
project(randpass)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable( randpass main.cpp)
target_link_libraries(randpass ${CONAN_LIBS})

