cmake_minimum_required(VERSION 3.10)  # Specify CMake version
project(YourProjectName)                # Replace with your project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Source files
set(SOURCES
    src/Matrix.cpp
    src/faddeev_leverrier.cpp
)

# Test files
set(TEST_SOURCES
    test/test_matrix.cpp
)

# Uncomment to create the main executable if needed
# add_executable(MainExecutable ${SOURCES})

# Create the test executable
add_executable(TestExecutable ${TEST_SOURCES} src/Matrix.cpp)

# Link gtest and gtest_main to your test executable
target_link_libraries(TestExecutable ${GTEST_LIBRARIES} pthread)

