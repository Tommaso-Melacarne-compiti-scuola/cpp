#!/bin/bash

# skip if no arguments are passed
if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    exit 1
fi

dir_to_build="$1"

find . -path "*${dir_to_build}*" -type d | while read -r dir; do
  find "$dir" -maxdepth 1 -type f -name "*.cpp" | while read -r file; do
    filename=$(basename "$file" ".cpp")
    # shellcheck disable=SC2164
    pushd "$dir" > /dev/null
    if g++ -Wall -Wextra -pedantic "$filename.cpp" -o "$filename"; then
      echo "Built $filename in $dir"
      # shellcheck disable=SC2164
      popd > /dev/null
    else
      echo "$filename failed to build in $dir"
    fi
  done
done