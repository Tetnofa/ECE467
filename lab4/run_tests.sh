#!/bin/bash

# Make the project first
make

# Create directory structure
mkdir -p ./tests/{my,ref,diff}

# Clean previous files
rm -rf ./tests/my/*
rm -rf ./tests/ref/*
rm -rf ./tests/diff/*

# Copy tests from storage to both directories
cp ./tests_storage/*.sc ./tests/my/
cp ./tests_storage/*.sc ./tests/ref/

# Process my tests
cd ./tests/my
for test_file in *.sc; do
    filename=$(basename "$test_file" .sc)
    ../../A4Gen "$test_file"
    /cad2/ece467f/llvm-project/build/bin/llvm-dis "${filename}.bc" -o "${filename}.ll"
done
cd ../..

# Process ref tests
cd ./tests/ref
for test_file in *.sc; do
    filename=$(basename "$test_file" .sc)
    ../../A4GenRef "$test_file"
    /cad2/ece467f/llvm-project/build/bin/llvm-dis "${filename}.bc" -o "${filename}.ll"
done
cd ../..

# Compare results
for test_file in ./tests/my/*.ll; do
    filename=$(basename "$test_file" .ll)
    diff <(tail -n +3 "./tests/my/${filename}.ll") \
         <(tail -n +3 "./tests/ref/${filename}.ll") > "./tests/diff/${filename}_diff.txt"
    
    if [ -s "./tests/diff/${filename}_diff.txt" ]; then
        echo "Differences found for $filename"
    elif [ ! -s "./tests/diff/${filename}_diff.txt" ]; then
        echo "Test passed for $filename"
    fi
done

find ./tests/diff -type f -name '*_diff.txt' -empty -delete