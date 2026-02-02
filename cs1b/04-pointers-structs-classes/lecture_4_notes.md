# Lecture 4 - Pointers, Structures, Classes, Header Files

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

### ⚠️ Common Mistake: `*ptr++` vs `(*ptr)++`

```cpp
int x = 5;
int *ptr = &x;

*ptr++;    // ❌ NOT what you think!
(*ptr)++;  // ✅ Increments the VALUE (x becomes 6)
```

**Why `*ptr++` doesn't work as expected:**
- `++` has **higher precedence** than `*`
- So `*ptr++` is parsed as `*(ptr++)` — increments the POINTER, then dereferences
- The pointer moves to the next memory address (garbage), not incrementing x

**What each expression does:**

| Expression | Meaning | Result |
|------------|---------|--------|
| `*ptr++` | `*(ptr++)` | Dereference, THEN move pointer (returns old value) |
| `(*ptr)++` | Increment value at ptr | x becomes 6 |
| `++*ptr` | `++(*ptr)` | Increment value at ptr | x becomes 6 |
| `*++ptr` | `*(++ptr)` | Move pointer first, then dereference |

**Rule of thumb:** When in doubt, use parentheses `(*ptr)++` to make intent clear.

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

## Dynamic Memory (Heap Allocation)

### Stack vs Heap

| Stack | Heap |
|-------|------|
| Automatic cleanup | Manual cleanup (`delete`) |
| Fast allocation | Slower allocation |
| Limited size (~1MB) | Large, flexible |
| Size known at compile time | Size can be decided at runtime |
| Dies when scope ends | Lives until you `delete` it |

```
STACK (automatic)          HEAP (manual)
┌─────────────┐           ┌─────────────┐
│ ptr = 0x7F  │ ───────►  │     42      │
└─────────────┘           └─────────────┘
  (pointer var)             (actual data)
```

### The `new` Operator

Allocates memory on the heap and returns a pointer to it:

```cpp
// Single value
int* ptr = new int;        // Uninitialized
int* ptr = new int(42);    // Initialized to 42

// Array
int* arr = new int[10];    // Array of 10 ints
```

### The `delete` Operator

Frees heap memory — **you MUST do this or memory leaks!**

```cpp
int* ptr = new int(42);
// ... use ptr ...
delete ptr;       // Free single value
ptr = nullptr;    // Good practice: avoid dangling pointer

int* arr = new int[10];
// ... use arr ...
delete[] arr;     // Free array (note the [])
arr = nullptr;
```

### Why Use Heap?

**1. Data outlives the function:**
```cpp
int* createOnStack() {
    int x = 42;
    return &x;         // ❌ BAD: x dies, pointer is garbage
}

int* createOnHeap() {
    int* p = new int(42);
    return p;          // ✅ OK: heap memory survives
}
```

**2. Size not known until runtime:**
```cpp
int n;
cin >> n;
// int arr[n];         // ❌ Can't do (size must be constant)
int* arr = new int[n]; // ✅ Works! Decide size at runtime
```

**3. Need large amounts of memory** (stack is limited)

### Common Mistakes

```cpp
// Memory leak — forgot to delete
void bad() {
    int* p = new int(5);
}  // p dies but heap memory is lost forever!

// Double delete — crashes!
int* p = new int(5);
delete p;
delete p;  // ❌ CRASH!

// Dangling pointer — points to freed memory
int* p = new int(5);
delete p;
*p = 10;   // ❌ Undefined behavior! Memory already freed
```

### Best Practice Pattern

```cpp
int* ptr = new int(42);   // 1. Allocate
// ... use ptr ...         // 2. Use
delete ptr;                // 3. Free
ptr = nullptr;             // 4. Nullify (prevents accidents)
```

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

---

## Classes

A **class** is similar to a struct but members are `private` by default. Use classes when you have member functions and need encapsulation.

### Class vs Struct

| Feature | Class | Struct |
|---------|-------|--------|
| Default access | `private` | `public` |
| Use when | Have member functions | Simple data grouping |
| Encapsulation | Better data protection | Less protection |

### Class Definition

```cpp
class Student {
private:           // Private by default (optional keyword)
    string name;
    int id;
    double gpa;

public:
    // Member functions go here
}; // Semicolon required!
```

### Access Specifiers

- **`private`**: Only accessible by member functions of the same class
- **`public`**: Accessible from anywhere in the program

```cpp
class Student {
private:
    string name;    // Hidden from outside
    int id;
    
public:
    void setName(string n);  // Interface to modify data
    string getName();        // Interface to access data
};
```

**You can mix access specifiers (but grouping is cleaner):**

```cpp
class Student {
private:
    string ssn;
public:
    string name;
private:          // Can switch back
    int secretScore;
public:           // And again
    int getScore();
};
```

### C++ vs Python: Access Control

| Python | C++ |
|--------|-----|
| `_private` is just a *hint* | `private:` is **enforced** by compiler |
| Nothing stops `obj._private = 5` | `obj.secret = 5` → **compile error** |
| "We're all adults here" | "The compiler is your parent" |

**Python access levels (convention only):**

```python
class Student:
    def __init__(self):
        self.public = "anyone"      # Public
        self._protected = "hint"    # Convention: please don't
        self.__private = "mangled"  # Name mangling

s = Student()
s._protected = "works"     # ✅ Python trusts you
s.__private              # ❌ AttributeError
s._Student__private      # ✅ But you can still access it!
```

**C++ access levels (enforced):**

```cpp
class Student {
private:
    int secret = 42;
public:
    int score = 100;
};

Student s;
cout << s.score;   // ✅ Works
cout << s.secret;  // ❌ COMPILE ERROR: 'secret' is private
```

**TL;DR:** C++ is a locked door. Python is a door with a "Please Knock" sign.

### Member Functions

Member functions can access all class members (private and public):

```cpp
class Student {
private:
    string name;
public:
    void setName(string n) {
        name = n;  // Can access private member
    }
    string getName() {
        return name;
    }
};

// Usage:
Student s;
s.setName("Alice");
cout << s.getName();  // Outputs: Alice
```

### Defining Functions Outside the Class

Use the **scope resolution operator** `::`:

```cpp
class Student {
private:
    string name;
public:
    void setName(string n);   // Declaration only
    string getName();
};

// Definition outside class
void Student::setName(string n) {
    name = n;
}

string Student::getName() {
    return name;
}
```

---

## Constructors

A **constructor** initializes an object when it's created.

**Rules:**
- Same name as the class
- No return type (not even `void`)
- Called automatically when object is created
- Can be overloaded

### Default Constructor

```cpp
class Student {
private:
    string name;
    int id;
public:
    Student() {           // Default constructor
        name = "Unknown";
        id = 0;
    }
};

Student s;  // Constructor called automatically
```

### Parameterized Constructor

```cpp
class Student {
public:
    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
    }
};

Student s("Bob", 12345, 3.8);  // Pass arguments
```

### Constructor Overloading

```cpp
class Student {
public:
    Student() {                         // Default
        name = "Unknown";
        id = 0;
    }
    Student(string n, int i, double g) { // Parameterized
        name = n;
        id = i;
        gpa = g;
    }
};

Student s1;                    // Calls default
Student s2("Bob", 123, 3.9);   // Calls parameterized
```

### Member Initializer List (Preferred)

```cpp
Student(string n, int i, double g) 
    : name(n), id(i), gpa(g) {  // More efficient
    // Constructor body (can be empty)
}
```

---

## Accessor and Mutator Functions

### Accessor (Getter)
Returns value of a private member:

```cpp
string getName() { return name; }
double getGpa() { return gpa; }
```

### Mutator (Setter)
Sets value with optional validation:

```cpp
void setGpa(double g) {
    if (g >= 0.0 && g <= 4.0) {  // Validation!
        gpa = g;
    }
}
```

---

## Array of Objects

```cpp
const int SIZE = 3;
Student students[SIZE];

for (int i = 0; i < SIZE; i++) {
    students[i].setName("Student " + to_string(i));
    cout << students[i].getName() << endl;
}
```

---

## Objects as Function Parameters

### Pass by Const Reference (Best Practice)

```cpp
void displayStudent(const Student &s) {
    cout << s.getName() << endl;
}

Student student("Alice", 123, 3.9);
displayStudent(student);  // No '&' in call
```

**Note:** Accessor functions should be marked `const`:
```cpp
string getName() const { return name; }
```

---

## The `this` Pointer

Implicit pointer to the calling object:

```cpp
void setName(string name) {
    this->name = name;  // Disambiguate parameter from member
}
```

---

## Quick Reference

| Operator | Name | Usage |
|----------|------|-------|
| `&` | Address operator | Get memory address of a variable |
| `*` | Dereference operator | Access value at pointer's address |
| `.` | Dot operator | Access struct/class member directly |
| `->` | Arrow operator | Access struct/class member via pointer |
| `::` | Scope resolution | Define member function outside class |
