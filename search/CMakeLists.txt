cmake_minimum_required(VERSION 3.10)

project(searches)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(search search_tests.cpp search.cpp)
target_include_directories(search PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(search GTest::GTest GTest::Main)