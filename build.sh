#!/bin/bash

# Creating build folder
echo "Creating build folder"
mkdir -p build
cd build

# Running CMake
echo "Running CMake"
cmake ..

# Running Make
echo "Running make"
make

# Moving executable to project folder
mv waveguide ../waveguide
