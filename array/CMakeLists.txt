cmake_minimum_required(VERSION 3.10)

project(arrays)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(array array_tests.cpp array.cpp)
target_include_directories(array PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(array GTest::GTest GTest::Main)