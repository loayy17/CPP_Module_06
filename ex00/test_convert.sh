#!/bin/bash

# Simple test runner for ex00/convert
# Runs a set of edge cases and prints the program output for manual inspection.

BINARY="./convert"
if [ ! -x "$BINARY" ]; then
  echo "Error: $BINARY not found or not executable. Build ex00 first."
  exit 2
fi

inputs=(
  "0"
  "nan"
  "nanf"
  "+inf"
  "+inff"
  "-inf"
  "-inff"
  "42.0f"
  "42.0"
  "42"
  "'a'"
  "a"
  "127"
  "128"
  "-1"
  "nonliteral"
)

for in in "${inputs[@]}"; do
  printf "\n--- Input: %s ---\n" "$in"
  # If input is of the form 'x' (with quotes) strip outer single quotes to emulate char literal
  if [[ "$in" =~ ^\'.\'$ ]]; then
    # pass without shell stripping
    arg="$in"
  else
    arg="$in"
  fi
  $BINARY "$arg"
done

exit 0
