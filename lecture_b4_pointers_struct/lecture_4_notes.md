# Lecture 4 - Pointers, Structures, Header Files

## Pointers

A pointer is a variable that holds a **memory address** of another variable - never a value directly.

### Memory Addresses
- Each memory location holds **one byte** and has a unique numerical address
- Each byte of a variable has an address
- Different data types use different amounts of memory:
  - `char` = 1 byte
  - `bool` = 1 byte
  - `int` = 4 bytes
  - `float` = 4 bytes

### Declaring Pointers

Use an asterisk (`*`) before the pointer variable name:

```cpp
char *ptr;           // Pointer to char
float *floatPtr;     // Pointer to float
char* charPtr;       // Also valid
string * strPtr;     // Also valid
```

**Note:** The asterisk can be placed next to the type, the variable name, or with spaces - all are valid.

### Address Operator (`&`)

Use the `&` operator to get a variable's memory address:

```cpp
char initial;           // Declare a variable
char *charPtr;          // Declare a pointer
charPtr = &initial;     // Assign address of initial to charPtr

// Or initialize in one line:
char *charPtr = &initial;
```

**Note:** An address in one pointer can be assigned to another pointer only if they are the **same data type**.

---

## Dereference Operator (`*`)

Also called the **indirection operator**. Used to access the value at the address a pointer holds.

```cpp
double deposit;         // Declare a variable
double *ptr;            // Declare a pointer
ptr = &deposit;         // Assign address to pointer
*ptr = 1050.0;          // Assigns 1050.0 to deposit (through the pointer)

cout << deposit;        // Output: 1050.0
cout << *ptr;           // Output: 1050.0 (same value, accessed via pointer)
```

### Pointer Type Safety

Pointers must match the data type of what they point to:

```cpp
int num1;
int *ptr = &num1;       // OK - both are int
int *temp;
temp = ptr;             // OK - both are int pointers

float *amtPtr;
amtPtr = ptr;           // ERROR - different data types
```

---

## Pointers and Arrays

- Array names are essentially pointers to the first element
- No `&` needed when assigning an array to a pointer

```cpp
const int SIZE = 5;
int numbers[SIZE] = {6, 8, 9, 3, 7};
int *ptr;

ptr = numbers;          // Assigns address of numbers[0] to ptr
                        // (no & needed for arrays)

for (int i = 0; i < SIZE; i++)
{
    cout << *ptr << endl;   // Output current element
    ptr++;                  // Move to next element
}
```

### Pointer Arithmetic

When you increment a pointer, it moves by the **size of the data type**:
- `int *ptr; ptr++;` moves the address by 4 bytes (size of int)
- `char *ptr; ptr++;` moves the address by 1 byte (size of char)

---

## Pointers as Function Parameters

Pointers give functions access to original variables (similar to reference parameters).

```cpp
#include <iostream>
using namespace std;

void getName(char *);
void displayName(char *);

const int SIZE = 30;

int main()
{
    char name[SIZE];
    char *ptr = name;       // Array address assigned to pointer

    getName(ptr);
    displayName(ptr);
    return 0;
}

void getName(char *pName)
{
    cout << "Enter name: ";
    cin.getline(pName, SIZE);
}

void displayName(char *pName)
{
    cout << "Hi " << pName << ".\n";
}
```

### Pointers vs References
- Generally, **reference variables are easier** to use than pointers
- However, **pointers to C-strings** work well and are easy to use

---

## Structures (struct)

A **structured data type** - a collection of components referred to by a single name.

### Key Concepts
- **struct** - Reserved word for structure
- **Object** - A struct variable is called an object
- **Data members** - The components/variables inside a struct
- Data members are **public** by default (unlike classes which are private by default)

### Convention
- Use **structs** when there are no member functions
- Use **classes** when there are member functions

### Defining a Structure

```cpp
struct Time             // Identifier starts with uppercase
{
    int hours;
    int minutes;
    int seconds;
};                      // Semicolon required!
```

**Note:** Memory is NOT allocated when the struct is defined - only when variables are declared.

### Declaring and Initializing Struct Variables

```cpp
struct Date
{
    int month;
    int day;
    int year;
};

int main()
{
    Date today = {3, 1, 2018};  // Initialization list
    Date payDay;                 // Declaration only
}
```

---

## Accessing Struct Members

### 1. Dot Operator (`.`)

Used with struct objects directly:

```cpp
Date payDay;
payDay.month = 3;
payDay.day = 1;
payDay.year = 2010;

cout << "Enter today's date (mmddyy): ";
cin >> today.month >> today.day >> today.year;

// Note: cin >> today; is WRONG - must access individual members
```

### 2. Arrow Operator (`->`)

Used with **pointers** to struct objects:

```cpp
struct Box
{
    int width;
    int height;
    int length;
};

Box shoeBox;
Box *ptr;               // Pointer to Box objects
ptr = &shoeBox;         // Assign address to pointer

ptr->width = 10;        // Access member via pointer
ptr->height = 6;
ptr->length = 12;
```

### Complete Example

```cpp
struct Box
{
    int width;
    int height;
    int length;
};

int main()
{
    Box *ptr;
    Box toolBox = {9, 12, 18};
    Box shoeBox = {7, 6, 12};

    ptr = &shoeBox;

    // Using dot operator
    cout << "Tool box: " << toolBox.width << " - "
         << toolBox.height << " - " << toolBox.length << endl;

    // Using arrow operator
    cout << "Shoe box: " << ptr->width << " - "
         << ptr->height << " - " << ptr->length << endl;
}
```

---

## Passing Structs to Functions

Pass by reference to avoid copying and allow modification:

```cpp
void getDate(Date &date);

int main()
{
    Date today;
    getDate(today);
    return 0;
}

void getDate(Date &date)
{
    cout << "Enter the date (mmddyy): ";
    cin >> date.month >> date.day >> date.year;
}
```

---

## Struct Constructors

A constructor initializes data members when an object is created.

```cpp
struct Box
{
    int width;
    int height;
    int length;

    // Constructor - same name as struct
    Box()
    {
        width = 0;
        height = 0;
        length = 0;
    }
};

// Now when declared, members are initialized to 0
Box myBox;  // width=0, height=0, length=0
```

---

## Array of Struct Objects

Store multiple struct objects (records) in an array:

```cpp
struct Record
{
    string name;
    int age;
};

const int SIZE = 5;

int main()
{
    Record records[SIZE];       // Array of 5 Record objects

    for (int i = 0; i < SIZE; i++)
    {
        cout << "AGE: ";
        cin >> records[i].age;
        cin.ignore();           // Clear newline from buffer
        cout << "NAME: ";
        getline(cin, records[i].name);
    }
}
```

---

## Header Files

Programmer-defined header files hold declarations of constants, function prototypes, struct/class specifications, etc.

### Creating a Header File

1. Create a new file with `.h` extension (e.g., `Box.h`)
2. Place struct specification in the file
3. Include in your program with quotes:

```cpp
#include "Box.h"        // User-defined header (quotes)
#include <iostream>     // System header (angle brackets)
```

### Header File Example (Box.h)

```cpp
// Box.h
struct Box
{
    int width;
    int height;
    int length;
};
```

### Using the Header

```cpp
#include <iostream>
#include "Box.h"        // Include your header

int main()
{
    Box myBox = {5, 10, 15};
    // ...
}
```

---

## Quick Reference

| Operator | Name | Usage |
|----------|------|-------|
| `&` | Address operator | Get memory address of a variable |
| `*` | Dereference operator | Access value at pointer's address |
| `.` | Dot operator | Access struct member directly |
| `->` | Arrow operator | Access struct member via pointer |
