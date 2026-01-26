# Lecture 3 - enum, namespaces, typedef, Recursion

## Enumeration Type (enum)

C++ allows programmers to create new data types using `enum`.

**Definition:** A user-defined data type whose domain is an ordered set of literal values expressed as identifiers.

### Syntax
```cpp
enum colors { BROWN, BLUE, RED, GREEN, YELLOW };
```

### Key Points
- Values are separated by commas
- Each identifier has a default integer value starting at 0:
  - `BROWN = 0`, `BLUE = 1`, `RED = 2`, `GREEN = 3`, `YELLOW = 4`
- Values are **ordered**: `BROWN < BLUE`
- Values must be **identifiers**, not characters or strings
  - `enum grades {'A', 'B', 'C'};` - **WRONG**
  - `enum grades { A, B, C, D, F };` - **Correct**

### Variable Declaration
```cpp
enum sports { BASKETBALL, FOOTBALL, SOCCER, BASEBALL };

int main()
{
    sports popularSport;           // Declaration
    sports mySport = FOOTBALL;     // Declaration with initialization
    popularSport = BASEBALL;       // Assignment
}
```

### Custom Integer Values
You can assign custom integer values to enum members:
```cpp
enum trafficLights { GREEN = 1, YELLOW = 2, RED = 4 };
```

### Operations on Enumeration Type
- **No math operations** allowed: `popularSport = mySport + 1;` - **WRONG**
- **Comparison operations** allowed (relational operators work):
  ```cpp
  if (mySport == yourSport)  // OK
  ```

---

## Namespaces

A namespace allows entities like classes, objects, and functions to be grouped together under a name.

### Syntax
```cpp
namespace identifier
{
    entities
}
```

### Example
```cpp
namespace first
{
    int var = 5;
}

namespace second
{
    double var = 3.1416;
}

int main()
{
    cout << first::var << endl;   // Output: 5
    cout << second::var << endl;  // Output: 3.1416
}
```

### Using Keyword
The `using` keyword introduces a name from a namespace into the current scope:
```cpp
int main()
{
    using first::x;
    using second::y;

    cout << x << endl;         // Uses first::x
    cout << y << endl;         // Uses second::y
    cout << first::y << endl;  // Fully qualified name still works
}
```

### using namespace std
- Means the program uses ANSI/ISO Standard C++ (official since 1998)
- Makes global identifiers like `cout` and `cin` from `<iostream>` available

---

## typedef Statement

`typedef` allows a programmer to create an alias (new name) for an existing data type.

**Note:** It does NOT create a new data type - just an additional name.

### Syntax
```cpp
typedef unsigned short int USHORT;

int main()
{
    USHORT width = 5;
    USHORT length;
}
```

---

## Runtime Stack

A place in memory where data is saved while a program runs.

### Key Concepts
- **LIFO** - Last In, First Out
- When a function is called, values and memory addresses are **pushed** onto the stack
- When a function returns, data is **popped** from the stack

### Activation Record (Stack Frame)

When a function is called, an activation record is created containing:

1. **Return address** - Memory address of the next instruction after the function call
2. **Actual parameters** - Values (arguments) passed to the function
3. **Local variables** - Variables declared inside the function
4. **Return value** - Space for the return value (if non-void)

### Memory Allocation Comparison

| Value-Returning Function | Void-Returning Function |
|--------------------------|-------------------------|
| Push storage for return value | - |
| Push actual parameters | Push actual parameters |
| Push return address | Push return address |
| Push local variables | Push local variables |

### Deallocation (in reverse order)

| Value-Returning Function | Void-Returning Function |
|--------------------------|-------------------------|
| Deallocate local variables | Deallocate local variables |
| Pop return address | Pop return address |
| Deallocate parameters | Deallocate parameters |
| Pop return value | - |

---

## Recursive Functions

A function that calls itself.

### Terminology
- **Recursive call** - A function call where the function being called is the same as the one making the call
- **Direct recursion** - A function directly calls itself
- **Indirect recursion** - A chain of function calls eventually returns to the originating function
- **Dynamic allocation** - Function parameters and local variables are bound to addresses at runtime

### Problem: Infinite Recursion
```cpp
void showMessage()
{
    cout << "This is a recursive function\n";
    showMessage();  // Recursive call - runs forever!
}
```

This causes a **stack overflow** - the stack grows until memory runs out.

### Solution: Base Case
```cpp
void showMessage(int times)
{
    if (times > 0)  // Control condition
    {
        cout << "This is a recursive function\n";
        showMessage(times - 1);  // Progress toward base case
    }
}
```

### Two Essential Components

1. **Base case** - A condition where the function returns without making a recursive call
2. **Recursive case** - The function calls itself with a smaller/simpler version of the problem

### Example: Count Characters in String
```cpp
int countChars(char letter, char message[], int index)
{
    if (message[index] == '\0')
    {
        return 0;  // Base case: end of string
    }
    else if (message[index] == letter)
    {
        // Recursive case: found match
        return 1 + countChars(letter, message, index + 1);
    }
    else
    {
        // Recursive case: no match
        return countChars(letter, message, index + 1);
    }
}
```

### Example: Greatest Common Divisor (GCD)
```cpp
int gcd(int x, int y)
{
    if (x % y == 0)
        return y;           // Base case
    else
        return gcd(y, x % y);  // Recursive case
}
```

### Considerations When Using Recursion

1. Is there a non-recursive (iterative) solution?
2. Does each recursive call make progress toward the base case?

### Recursion vs Iteration
- Recursive solutions can be **less efficient** than iterative solutions
- However, many problems have **simple, elegant** recursive solutions
- Any recursive algorithm can be implemented iteratively using loops
