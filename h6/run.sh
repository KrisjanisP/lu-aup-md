#!/bin/bash

# Check if filename and input file were provided
if [ "$#" -ne 2 ]; then
    echo "Usage: ./run.sh <source_file.cpp> <input_file>"
    exit 1
fi

# Extract the file name without the extension
base_filename=$(basename -- "$1")
extension="${base_filename##*.}"
base_filename="${base_filename%.*}"

# Check if the file has the .cpp extension
if [ "$extension" != "cpp" ]; then
    echo "The file must have a .cpp extension"
    exit 1
fi

# Create a temporary directory
temp_dir=$(mktemp -d)

# Compile the C++ code and place the executable in the temporary directory
g++ -o "${temp_dir}/${base_filename}" "$1"
compile_status=$?

# Check if the compilation was successful
if [ $compile_status -eq 0 ]; then
    # Execute the program and pass the input file as an argument
    "${temp_dir}/${base_filename}" "$2"
    # Remove the temporary directory along with the executable
    rm -r "${temp_dir}"
else
    echo "Compilation failed"
    # Clean up by removing the temporary directory
    rm -r "${temp_dir}"
fi