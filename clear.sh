#!/bin/bash

for file in *; do
  if [[ -f "$file" && ! "$file" =~ \. && -x "$file" ]]; then
    echo "Removed ex file: $file"
    rm "$file"
  fi
done
