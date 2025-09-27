42 C++ Module 06 — Casts

Build & run
-----------
All exercises compile with:

    cd ex00 && make
    cd ex01 && make
    cd ex02 && make

Binaries produced:
- ex00/convert
- ex01/serializer
- ex02/typeIdentifier

Formatting & Standard
---------------------
- Code compiles with `-std=c++98 -Wall -Wextra -Werror`.
- Headers include guards and are self-contained.

Tests performed
---------------
- ex00: Functional tests + strict comparator `ex00/test_convert_strict.sh` (all OK).
- ex00: `ex00/test_convert.sh` (informal outputs).
- ex01: Ran `./serializer` and validated output.
- ex02: Ran `./typeIdentifier` and observed expected behaviour.

Memory checks
-------------
- Ran `valgrind --leak-check=full` on each binary with representative inputs — no leaks and no errors reported.

Changes made (for fixes & compliance)
------------------------------------
- ex00/ScalarConverter.hpp: added `#include <string>`.
- ex00/TypeConverter.cpp: added `<cctype>, <limits>`, handled quoted char literals ('a').
- ex00/test_convert.sh and ex00/test_convert_strict.sh: created test scripts.
- ex01/Data.hpp: added `#include <string>`.

Next steps / Recommendations
----------------------------
- Run final `make fclean && make` in each exercise and verify binaries before submitting.
- Optionally run valgrind locally on the target environment again.

Good luck with your defense!
