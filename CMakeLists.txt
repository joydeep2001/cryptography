# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(matrix_inverse)

# Enable testing
enable_testing()

# Add GoogleTest as a submodule or package
add_subdirectory(googletest)

add_executable(MyTests test.cpp)

# Link GoogleTest
target_link_libraries(MyTests gtest gtest_main)

add_test(NAME MyTests COMMAND MyTests)
