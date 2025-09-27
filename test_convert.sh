#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

declare -A expected_char
expected_char["0"]="Non displayable"
expected_char["nan"]="impossible"
expected_char["42.0f"]="'*'"
expected_char["-42"]="impossible"
expected_char["a"]="'a'"
expected_char["42.0"]="'*'"
expected_char["-4.2f"]="impossible"
expected_char["4.2f"]="impossible"
expected_char["+inff"]="impossible"
expected_char["-inff"]="impossible"
expected_char["nanf"]="impossible"
expected_char["+inf"]="impossible"
expected_char["-inf"]="impossible"


declare -A expected_int
expected_int["0"]="0"
expected_int["nan"]="impossible"
expected_int["42.0f"]="42"
expected_int["-42"]="-42"
expected_int["a"]="97"
expected_int["42.0"]="42"
expected_int["-4.2f"]="-4"
expected_int["4.2f"]="4"
expected_int["+inff"]="impossible"
expected_int["-inff"]="impossible"
expected_int["nanf"]="impossible"
expected_int["+inf"]="impossible"
expected_int["-inf"]="impossible"


declare -A expected_float
expected_float["0"]="0.0f"
expected_float["nan"]="nanf"
expected_float["42.0f"]="42.0f"
expected_float["-42"]="-42.0f"
expected_float["a"]="97.0f"
expected_float["42.0"]="42.0f"
expected_float["-4.2f"]="-4.2f"
expected_float["4.2f"]="4.2f"
expected_float["+inff"]="+inff"
expected_float["-inff"]="-inff"
expected_float["nanf"]="nanf"
expected_float["+inf"]="+inff"
expected_float["-inf"]="-inff"


declare -A expected_double
expected_double["0"]="0.0"
expected_double["nan"]="nan"
expected_double["42.0f"]="42.0"
expected_double["-42"]="-42.0"
expected_double["a"]="97.0"
expected_double["42.0"]="42.0"
expected_double["-4.2f"]="-4.2"
expected_double["4.2f"]="4.2"
expected_double["+inff"]="+inf"
expected_double["-inff"]="-inf"
expected_double["nanf"]="nan"
expected_double["+inf"]="+inf"
expected_double["-inf"]="-inf"

# Only test assignment-compliant, displayable, and pseudo-literal cases
for input in "0" "nan" "42.0f" "-42" "a" "42.0" "-4.2f" "4.2f" "+inff" "-inff" "nanf" "+inf" "-inf"; do
  output=$(./ex00/convert "$input")
  act_char=$(echo "$output" | grep '^char:' | sed 's/char: //')
  act_int=$(echo "$output" | grep '^int:' | sed 's/int: //')
  act_float=$(echo "$output" | grep '^float:' | sed 's/float: //')
  act_double=$(echo "$output" | grep '^double:' | sed 's/double: //')

  exp_char="${expected_char[$input]}"
  exp_int="${expected_int[$input]}"
  exp_float="${expected_float[$input]}"
  exp_double="${expected_double[$input]}"

  res_char="${RED}FAIL${NC}"; [ "$act_char" = "$exp_char" ] && res_char="${GREEN}PASS${NC}"
  res_int="${RED}FAIL${NC}"; [ "$act_int" = "$exp_int" ] && res_int="${GREEN}PASS${NC}"
  res_float="${RED}FAIL${NC}"; [ "$act_float" = "$exp_float" ] && res_float="${GREEN}PASS${NC}"
  res_double="${RED}FAIL${NC}"; [ "$act_double" = "$exp_double" ] && res_double="${GREEN}PASS${NC}"

  echo -e "${YELLOW}====================[ Input: '$input' ]====================${NC}"
  printf "  %-10s | %-20s | %-20s | %s\n" "Type" "Expected" "Actual" "Result"
  echo "  ---------------------------------------------------------------"
  printf "  %-10s | %-20s | %-20s | %b\n" "char" "$exp_char" "$act_char" "$res_char"
  printf "  %-10s | %-20s | %-20s | %b\n" "int" "$exp_int" "$act_int" "$res_int"
  printf "  %-10s | %-20s | %-20s | %b\n" "float" "$exp_float" "$act_float" "$res_float"
  printf "  %-10s | %-20s | %-20s | %b\n" "double" "$exp_double" "$act_double" "$res_double"
  echo -e "${YELLOW}----------------------------------------------------------${NC}\n"
done
