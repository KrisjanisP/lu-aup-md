cmake_minimum_required(VERSION 3.14)
project(g17)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
    MyListSolution
    MyListSolution.cpp
)

add_executable(
    unit-testing 
    unit-testing.cpp
)

target_link_libraries(
    unit-testing
    MyListSolution
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit-testing)