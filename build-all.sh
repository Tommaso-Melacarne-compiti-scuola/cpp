#!/bin/bash

find . -name "*.cpp" -type f -exec bash -c '
  for file do
    filename=$(basename "$file" ".cpp")
    dir=$(dirname "$file")
    pushd "$dir" > /dev/null
    g++ -Wall -Wextra -pedantic "$filename.cpp" -o "$filename" && echo "Built $filename in $dir"
    popd > /dev/null
  done
' bash {} +