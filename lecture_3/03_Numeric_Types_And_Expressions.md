# Lecture 3: Numeric Types, Expressions, and Output

## C++ Numeric Data Types

### Integral Data Types
Whole numbers (no fractions).
- `char`: 1 byte (e.g., `char initial = 'A';`)
- `short`: 2 bytes (e.g., `short number = 21;`)
- `int`: 4 bytes (e.g., `int age = 21;`)
- `long long`: 8 bytes (e.g., `long long value = 12345678901234;`)

### Real Number Data Types
Whole & fractional parts.
- `float`: 4 bytes (e.g., `float tax = 125.12;`)
- `double`: 8 bytes (e.g., `double natlDebt = 1234567890123.12;`)

## Assignment, Expressions, and Operators

### Operators
- **Assignment** (`=`): Assigns right value to left variable.
  ```cpp
  val3 = FIRST_VALUE + val2;
  ```
- **Equality** (`==`): Comparison.
  ```cpp
  if (num3 == num4)
  ```
- **Arithmetic**: `+`, `-`, `*`, `/`, `%` (Modulus - integers only).

### Integer Division vs Float Division
- **Integer Division**: Truncates remainder.
  ```cpp
  int num1 = 8 / 2; // 4
  int num2 = 9 / 2; // 4
  ```
- **Float Division**: Gives decimals.
  ```cpp
  float num6 = 8.0 / 2.0; // 4.0
  float num7 = 5.0 / 2.0; // 2.5
  ```

### Type Coercion and Casting
- **Automatic Coercion**: Smaller types convert to larger types in mixed expressions.
  ```cpp
  float num1 = 13 / 7.0; // 1.85714 (int 13 promoted to float)
  int num2 = 13 / 7;     // 1 (integer division)
  ```
- **Explicit Casting**:
  ```cpp
  // C++ style (recommended)
  num1 = num2 / static_cast<float>(num3);
  
  // Old C style
  num1 = num2 / float(num3); 
  ```
- **Truncation**: Assigning larger type to smaller type truncates.
  ```cpp
  double myDouble = 3.52;
  cout << int(myDouble); // 3
  ```

### Compound Expressions & Precedence
- **Order**:
  1. `*`, `/`, `%`
  2. `+`, `-`
  3. `=` (Last)
- Parentheses `()` evaluate inside out.

## Standard Library Math Functions
Include `<cmath>`.
- `abs(i)`: Absolute value (int)
- `fabs(x)`: Absolute value (float)
- `pow(x, y)`: Power (doubles)
- `sqrt(x)`: Square root (double)

## Formatting Output
- **Spaces**: `cout << num1 << ' ' << num2;`
- **Manipulators** (include `<iomanip>`):
  - `setw(n)`: Set width (right-justified default).
  - `left`: Left-justify.
  - `endl`: New line.
  - `fixed`: Decimal formatting.
  - `showpoint`: Force decimal point.
  - `setprecision(n)`: Controls decimal places.
  
  ```cpp
  cout << fixed << setprecision(2) << '$' << tax; // $17.00
  ```

## Additional Useful Functions
- **Limits** (`<limits>`):
  ```cpp
  cout << numeric_limits<int>::min();
  cout << numeric_limits<int>::max();
  ```
- **Type Info** (`<typeinfo>`):
  ```cpp
  cout << typeid(myVariable).name();
  ```
