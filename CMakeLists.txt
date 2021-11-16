cmake_minimum_required(VERSION 3.20)
project(stack)

set(CMAKE_CXX_STANDARD 17)
add_executable(stack1 main1.cpp stack1.hpp)
add_executable(stack2 main2.cpp stack2.hpp)
add_subdirectory(Google_test)
