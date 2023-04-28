cmake_minimum_required(VERSION 3.7)
project(hello CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(RDKit REQUIRED)
find_package(Boost COMPONENTS serialization REQUIRED)

add_executable(hello hello.cpp)

target_link_libraries(hello RDKit::GraphMol RDKit::SmilesParse)
