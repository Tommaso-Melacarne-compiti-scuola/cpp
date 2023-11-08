#!/bin/bash

cd assignments || exit

mkdir -p zip

for folder in ./*; do
  if [ -d "$folder" ]; then
    base=$(basename "$folder")
    zip -r "zip/Melacarne-$base.zip" "$folder"
  fi
done