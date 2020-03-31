cmake_minimum_required(VERSION 3.0.0)
project(task VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_executable(task main.cpp)
add_executable(tester testRunner.cpp)

add_test(NAME default WORKING_DIRECTORY ..\\tests COMMAND tester test1.txt)
add_test(NAME list_of_same_numbers WORKING_DIRECTORY ..\\tests COMMAND tester test2.txt)
add_test(NAME single_number WORKING_DIRECTORY ..\\tests COMMAND tester test3.txt)
add_test(NAME two_numbers WORKING_DIRECTORY ..\\tests COMMAND tester test4.txt)
add_test(NAME large_array WORKING_DIRECTORY ..\\tests COMMAND tester test5.txt)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
