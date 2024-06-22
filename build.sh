#!/bin/bash

# Script to build the entire C++ project

# Ensure we are in the root directory of the project
cd "$(dirname "$0")" || exit 1

# Create a build directory if it doesn't exist
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit 1

# Run CMake to configure the project
echo "Running CMake..."
cmake ..

# Build the project using make (adjust the number of threads as needed)
echo "Building project..."
make -j$(nproc)

# Optionally, run tests if you have them configured with CTest
echo "Running tests..."
ctest

# Optionally, install the project if you have an install target in your CMakeLists.txt
# Uncomment the lines below if you have 'make install' configured in your CMakeLists.txt
# echo "Installing project..."
# sudo make install

echo "Build process complete."
