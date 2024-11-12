#!/bin/bash

# Make the project first
make

# Create results directory if it doesn't exist
mkdir -p ./tests/results

# Clear previous diff files
rm -f ./tests/results/*

# Loop through all .sc files in tests directory
for test_file in ./tests/*.c; do
    # Get just the filename without path and extension
    filename=$(basename "$test_file" .sc)
    
    # Run your program
    ./A3Sema "$test_file" &> "./tests/results/${filename}_me.out"
    
    # Run reference program
    ./A3SemaRefPrint "$test_file" &> "./tests/results/${filename}_ref.out"
    
    # Compare outputs and save diff to separate file
    diff "./tests/results/${filename}_me.out" "./tests/results/${filename}_ref.out" &> "./tests/results/${filename}_diff.out"
    
    # Print status
    if [ -s "./tests/results/${filename}_diff.out" ]; then
        echo "Differences found for $filename"
    else
        echo "Test passed for $filename"
    fi
done 