#!/bin/bash

# Define an array of cpp filenames to ignore (without .cpp extension)
IGNORE_FILES=("template")

export IGNORE_FILES BashArrayToString="${IGNORE_FILES[*]}"

find . -name "*.cpp" -type f -exec bash -c '
  for file do
    filename=$(basename "$file" ".cpp")
    dir=$(dirname "$file")

    # Ignore files in the IGNORE_FILES array
    if grep -oqwF "$filename" <<<"${BashArrayToString}"; then
      continue
    fi

    pushd "$dir" > /dev/null
    g++ -Wall -Wextra -pedantic "$filename.cpp" -o "$filename" && echo "Built $filename in $dir"
    popd > /dev/null
  done
' bash {} +