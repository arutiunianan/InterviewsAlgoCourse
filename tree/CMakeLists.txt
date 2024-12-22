cmake_minimum_required(VERSION 3.10)

project(trees)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(tree tree_tests.cpp tree.cpp)
target_include_directories(tree PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(tree GTest::GTest GTest::Main)