#!/bin/bash

# Make the project first
make

# Create directory structure
mkdir -p ./tests/{results,diff}

# Clean previous files
rm -rf ./tests/results/*
rm -rf ./tests/diff/*

# Copy tests from storage to directories
cp ./tests_storage/*.ll ./tests/results/

# Process my tests
cd ./tests/results
for test_file in *.ll; do
    filename=$(basename "$test_file" .ll)
    /cad2/ece467f/llvm-project/build/bin/opt -load-pass-plugin=../../libA5Dom.so -passes="A5Dom" -disable-output "${filename}.ll" >> "${filename}_my.out" 2>&1
    /cad2/ece467f/llvm-project/build/bin/opt -load-pass-plugin=../../libA5DomRef.so -passes="A5Dom" -disable-output "${filename}.ll" >> "${filename}_ref.out" 2>&1
done
cd ../..

# Compare results
for test_file in ./tests_storage/*.ll; do
    filename=$(basename "$test_file" .ll)
    diff "./tests/results/${filename}_my.out" "./tests/results/${filename}_ref.out" > "./tests/diff/${filename}_diff.txt"
    
    if [ -s "./tests/diff/${filename}_diff.txt" ]; then
        echo "Differences found for $filename"
    elif [ ! -s "./tests/diff/${filename}_diff.txt" ]; then
        echo "Test passed for $filename"
    fi
done

find ./tests/diff -type f -name '*_diff.txt' -empty -delete