project(Google_test)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Test_run1 ../stack1.hpp test1.cpp)
add_executable(Google_Test_run2 ../stack1.hpp test2.cpp)
target_link_libraries(Google_Test_run1 gtest gtest_main)
target_link_libraries(Google_Test_run2 gtest gtest_main)