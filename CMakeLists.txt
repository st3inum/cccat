cmake_minimum_required(VERSION 3.10)
project(cccat)

set(CMAKE_CXX_STANDARD 20)

# Find Boost
find_package(Boost REQUIRED COMPONENTS program_options)

# Add source files
set(SOURCES src/main.cpp src/helper.cpp)

# Include directories
include_directories(include)

# Create executable
add_executable(cccat ${SOURCES})

# Link Boost libraries
target_link_libraries(cccat Boost::program_options)

# Add tests
enable_testing()
add_executable(ccwc_tests tests/test_add.cpp src/helper.cpp)
add_test(NAME ccwcTests COMMAND ccwc_tests)
