#!/bin/bash
# Strict comparator for ex00/convert
# Exits with non-zero if any case doesn't match exactly the expected output.

BINARY="./convert"
if [ ! -x "$BINARY" ]; then
  echo "Error: $BINARY not found or not executable. Build ex00 first."
  exit 2
fi

declare -A expected
expected[0]=$(cat <<'EOS'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOS
)
expected[nan]=$(cat <<'EOS'
char: impossible
int: impossible
float: nanf
double: nan
EOS
)
expected[nanf]="${expected[nan]}"
expected[+inf]=$(cat <<'EOS'
char: impossible
int: impossible
float: +inff
double: +inf
EOS
)
expected[+inff]="${expected[+inf]}"
expected[-inf]=$(cat <<'EOS'
char: impossible
int: impossible
float: -inff
double: -inf
EOS
)
expected[-inff]="${expected[-inf]}"
expected[42.0f]=$(cat <<'EOS'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOS
)
expected[42.0]=$(cat <<'EOS'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOS
)
expected[42]="${expected[42.0]}"
expected["'a'"]=$(cat <<'EOS'
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOS
)
expected[a]="${expected["'a'"]}"
expected[127]=$(cat <<'EOS'
char: Non displayable
int: 127
float: 127.0f
double: 127.0
EOS
)
expected[128]=$(cat <<'EOS'
char: impossible
int: 128
float: 128.0f
double: 128.0
EOS
)
expected[-1]=$(cat <<'EOS'
char: impossible
int: -1
float: -1.0f
double: -1.0
EOS
)
expected[nonliteral]=$(cat <<'EOS'
char: impossible
int: impossible
float: impossible
double: impossible
EOS
)

inputs=(0 nan nanf +inf +inff -inf -inff 42.0f 42.0 42 "'a'" a 127 128 -1 nonliteral)

fail=0
for in in "${inputs[@]}"; do
  out=$("$BINARY" "$in" 2>/dev/null)
  exp="${expected[$in]}"
  if [ "$out" != "$exp" ]; then
    echo "FAILED for input: $in"
    echo "Expected:"
    echo "----------------"
    echo "$exp"
    echo "----------------"
    echo "Got:"
    echo "----------------"
    echo "$out"
    echo "----------------"
    fail=1
  else
    echo "OK: $in"
  fi
done

exit $fail
