# Struct in Header File Example

Demonstrates defining a struct in a separate `.h` file and using it in `main.cpp`.

## Files

| File | Purpose |
|------|---------|
| `Student.h` | Struct definition (the "blueprint") |
| `main.cpp` | Uses the struct |

## Key Concepts

1. **Header guards** (`#ifndef`, `#define`, `#endif`) prevent multiple inclusion
2. **Include with quotes** for local headers: `#include "Student.h"`
3. **Initializer list** must match struct member order: `{ id, name, gpa }`

## Compile & Run

```bash
g++ main.cpp -o main
./main
```

Note: You don't compile `.h` files directly — they're included into `.cpp` files.
