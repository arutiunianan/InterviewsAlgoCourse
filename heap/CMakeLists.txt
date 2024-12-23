cmake_minimum_required(VERSION 3.10)

project(heaps)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

add_executable(heap heap_tests.cpp heap.cpp)
target_include_directories(heap PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(heap GTest::GTest GTest::Main)