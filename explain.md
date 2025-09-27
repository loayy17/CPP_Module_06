# 🎯 Casting in C++98 – Complete Guide

Casting = **converting a value from one type to another**.  
C++ provides 4 explicit cast operators (safer than C-style casts):

1. `static_cast`
2. `reinterpret_cast`
3. `const_cast`
4. `dynamic_cast`

---

## 🔹 What Does Casting Mean?
Casting is like telling the compiler:  
👉 “Treat this value or object as if it were another type.”

Examples:
- Converting numbers: `double → int`
- Changing how memory is viewed: pointer ↔ integer
- Adding/removing `const`
- Checking real type at runtime in polymorphism

---

# 🟦 1. `static_cast`
- **Safe conversions** checked at compile time.
- Used for:
  - Numeric conversions
  - Upcasting (`Derived* → Base*`)

```cpp
#include <iostream>
using namespace std;

int main() {
    double d = 9.8;
    int i = static_cast<int>(d);   // 9.8 → 9
    cout << "double " << d << " -> int " << i << endl;

    char c = static_cast<char>(65);
    cout << "65 as char: " << c << endl;
}
```

### ASCII Visualization

```
[d = 9.8]   ---static_cast--->   [i = 9]
[65]       ---static_cast--->   ['A']
```

---

# 🟧 2. `reinterpret_cast`

* **Low-level cast** (bit reinterpretation).
* Does not change the value, just how bits are **viewed**.
* Used for:

  * Pointer ↔ Integer
  * One pointer type ↔ Another

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* p = &x;

    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    cout << "Pointer as int: " << addr << endl;

    int* back = reinterpret_cast<int*>(addr);
    cout << "Back to pointer: " << *back << endl;
}
```

### ASCII Visualization

```
p (0x7ffe...) --reinterpret_cast--> addr (integer number)
addr ---------reinterpret_cast----> p (back to pointer)
```

---

# 🟩 3. `const_cast`

* **Removes or adds `const`** qualifier.
* Useful when API does not accept `const`.

```cpp
#include <iostream>
using namespace std;

void print(char* msg) {
    cout << msg << endl;
}

int main() {
    const char* text = "Hello";
    print(const_cast<char*>(text));  // remove const
}
```

⚠️ Don’t modify memory that was originally `const` → **undefined behavior**.

### ASCII Visualization

```
[ const char* ] --const_cast--> [ char* ]
```

---

# 🟨 4. `dynamic_cast`

* **Safe downcasting** in inheritance (runtime check).
* Requires at least one `virtual` function.
* Returns:

  * Pointer → `nullptr` if cast fails
  * Reference → throws `std::bad_cast`

```cpp
#include <iostream>
using namespace std;

class Base { public: virtual ~Base() {} };
class Derived : public Base { public: void hello(){ cout << "Derived says hi!\n"; } };

int main() {
    Base* b = new Derived;

    if (Derived* d = dynamic_cast<Derived*>(b)) {
        d->hello();  // success
    } else {
        cout << "Cast failed\n";
    }

    delete b;
}
```

### ASCII Visualization

```
Base* → Derived*   (runtime check)
✔ valid → pointer returned
✘ invalid → nullptr
```

---

# 📊 Comparison Table

| Cast Type          | Purpose                       | Safe?   | Example                                         |
| ------------------ | ----------------------------- | ------- | ----------------------------------------------- |
| `static_cast`      | Normal conversions, upcasting | ✅ Yes   | `int i = static_cast<int>(3.5);`                |
| `reinterpret_cast` | Raw bit reinterpretation      | ⚠️ No   | `uintptr_t n = reinterpret_cast<uintptr_t>(p);` |
| `const_cast`       | Add/remove const              | ⚠️ Care | `const_cast<char*>(str)`                        |
| `dynamic_cast`     | Runtime-checked downcasting   | ✅ Yes   | `Derived* d = dynamic_cast<Derived*>(b);`       |

---

# 🖼 Visual Overview (Mermaid Diagram)

```mermaid
flowchart TD
    A[C-style Cast (unsafe)] --> B[static_cast (safe conversions)]
    A --> C[reinterpret_cast (low-level, bit view)]
    A --> D[const_cast (add/remove const)]
    A --> E[dynamic_cast (runtime downcast)]

    B -->|Numbers & Upcast| F((Safe))
    C -->|Pointer ↔ Integer| G((Dangerous))
    D -->|API Compatibility| H((Careful))
    E -->|Polymorphism| I((Safe at runtime))
```

---

# 📝 Final Example – All Casts Together

```cpp
#include <iostream>
using namespace std;

class Base { public: virtual ~Base() {} };
class Derived : public Base { public: void hello(){ cout << "Derived says hi!\n"; } };

int main() {
    // 1. static_cast
    double d = 5.9;
    int i = static_cast<int>(d);
    cout << "static_cast -> " << i << endl;

    // 2. reinterpret_cast
    int x = 42;
    int* p = &x;
    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    cout << "reinterpret_cast -> pointer as int: " << addr << endl;

    // 3. const_cast
    const char* msg = "Hello";
    cout << "const_cast -> ";
    cout << const_cast<char*>(msg) << endl;

    // 4. dynamic_cast
    Base* b = new Derived;
    if (Derived* dptr = dynamic_cast<Derived*>(b)) {
        dptr->hello();
    }
    delete b;

    return 0;
}
```

---

# ✅ Key Takeaways

* **`static_cast`** → normal safe conversions.
* **`reinterpret_cast`** → dangerous, raw memory re-interpretation.
* **`const_cast`** → remove/add `const`.
* **`dynamic_cast`** → runtime-checked downcasting.
* Avoid **C-style casts** → prefer explicit C++ casts.

---

This single file includes:  
✔ What casting means  
✔ The four cast types  
✔ When to use each one  
✔ Detailed code examples  
✔ ASCII memory diagrams  
✔ Mermaid visualization  

Do you want me to also **add real memory address printouts** (with `&variable` outputs) in examples so you can see actual addresses when running?
