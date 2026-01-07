# Lecture 2: Syntax and the Program Development Process

## C++ Syntax & Program Development

### `main` Function
Every C++ program must have a `main` function where execution starts.
```cpp
int main() {
    // function body
    return 0;
}
```
- Heading is the first line.
- Braces `{}` enclose the body.

### Statements & Syntax
- Formal rules for writing valid C++ instructions.
- Each statement ends with a **semicolon** (`;`).
- Strings must be in **double quotes**.
```cpp
cout << "Hello. Do you want to learn C++?" << endl;
```

## Variables
Named memory locations to hold values.
- Declare at top of `main` for clarity.
- Must be declared before use. Declaration does not automatically initialize them.

```cpp
int age;
int number;
```

### Identifiers
- Variable names.
- Must start with a letter or underscore.
- No spaces or reserved words.
- Use descriptive names (e.g., `firstName`, `intRate`).

### Data Types
- **int**: Whole numbers (4 bytes).
  ```cpp
  int weight;
  ```
- **char**: Single character (1 byte). Uses **single quotes**.
  ```cpp
  char grade = 'A';
  ```
- **string**: Sequence of characters. Uses **double quotes**. Needs `<string>` header.
  ```cpp
  #include <string>
  // ...
  string firstName = "John";
  ```

### Constants
Declared with `const`. Names usually in ALL CAPS.
```cpp
const string MESSAGE = "Error: Please resubmit!";
const char LETTER = 'y';
```

## Input & Output
Requires `#include <iostream>` and `using namespace std;`.

### Output (`cout`)
- Predefined variable for standard output.
- Uses **Insertion Operator** (`<<`).
```cpp
cout << "Hi there!";
cout << 6 << endl << 7 << endl;
```
- `endl` moves output to the next line.

### Input (`cin`)
- Reads input from keyboard.
- Uses **Extraction Operator** (`>>`).
```cpp
int age;
cout << "Enter your age: ";
cin >> age;
cout << "I didn't know you were " << age << " years old." << endl;
```

## Comments
- **Single-line**: `// comment`
- **Multi-line**: `/* comment */`

## Variable Initialization
- Variables are **not** automatically initialized (indeterminate value).
- **Explicit initialization** is best practice.
  - Numeric: `0`
  - Boolean: `false`
  - Pointer: `nullptr`

## Comparison: C vs. C++ Output
**C (1970)**
```c
#include <stdio.h>
printf("This is a string literal. C");
```

**C++ (1985)**
```cpp
#include <iostream>
using namespace std;
cout << "This is a string literal. C++";
```
