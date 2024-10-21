cmake_minimum_required(VERSION 3.10)

project(lists)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(list list_tests.cpp list.cpp)
target_include_directories(list PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(list GTest::GTest GTest::Main)