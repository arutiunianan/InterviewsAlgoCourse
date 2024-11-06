cmake_minimum_required(VERSION 3.10)

project(sorts)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(sort sort_tests.cpp sort.cpp)
target_include_directories(sort PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(sort GTest::GTest GTest::Main)