cmake_minimum_required(VERSION 3.10)
project(ccwc)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source files
set(SOURCES 
    src/main.cpp 
    src/myheader.cpp
)

# Include directories
include_directories(include)

# Create executable
add_executable(ccwc ${SOURCES})

# Add tests
enable_testing()
add_executable(ccwc_tests tests/test_add.cpp src/myheader.cpp)
add_test(NAME ccwcTests COMMAND ccwc_tests)
