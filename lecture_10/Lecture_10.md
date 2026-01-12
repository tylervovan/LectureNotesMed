# Lecture #10: Pointers, Dot Operator, and Struct

## Pointers
A pointer can only hold a memory address - never a value.
- A **pointer** is a variable that holds an address of another variable.

**Memory Address**: Each memory location holds one byte and has a unique numerical address.
- Each byte of a variable has an address.

### Declaration
To declare a pointer, an asterisk must be in front of each pointer variable.
```cpp
char *ptr;       // Declares a pointer variable that points to char
float *floatPtr; // Points to float
char* charPtr;   // Valid syntax
string * strPtr; // Valid syntax
```

### Address Operator (&)
Use the `&` operator to assign a memory address to a pointer.

```cpp
char initial = 'T';
char *charPtr;
charPtr = &initial; // Assign the address of initial to charPtr
```
*Note*: To initialize a pointer: `char *charPtr = &initial;`
*Note*: An address held in one pointer can be assigned to another pointer, providing they are of the same data type.

## De-reference Operator (*)
Also called the indirection operator. When a pointer points to a variable, the value held in the variable can be accessed (de-referenced) by using the `*` operator.

```cpp
double deposit;
double * ptr;
ptr = &deposit;

*ptr = 1050.0; // Assigns 1050.0 to deposit via the pointer

cout << deposit; // Output: 1050.0
cout << *ptr;    // Output: 1050.0
```

### Pointer Compatibility
Pointers must point to the same data type.
```cpp
int num1;
int * ptr = &num1;
int * temp;
temp = ptr;      // OK: both are int pointers

float * amtPtr;
amtPtr = ptr;    // Error: different data types
```

## Pointers, Arrays, and Pointer Arithmetic
You can assign a pointer to the first element in an array and access elements by incrementing the pointer.

```cpp
int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {6, 8, 9, 3, 7};
    int *ptr;
    
    ptr = numbers; // Assigns address of numbers[0] to ptr
    
    for (int i = 0; i < SIZE; i++) {
        cout << *ptr << endl;
        ptr++; // Increments address to next element (e.g., +4 bytes for int)
    }
    return 0;
}
```

## Pointers as Function Parameters
A pointer can be used as a function parameter, giving the function access to the original variable (similar to pass-by-reference).

```cpp
#include <iostream>
using namespace std;

void getName(char *);
void displayName(char *);
const int SIZE = 30;

int main() {
    char name[SIZE];
    char * ptr = name;
    getName(ptr);
    displayName(ptr);
    return 0;
}

void getName(char * pName) {
    cout << "Enter name: ";
    cin.getline(pName, SIZE);
}

void displayName(char * pName) {
    cout << "Hi " << pName << ".\n";
}
```

## Structs (Structures)
A **struct** is a structured data type that allows a collection of components (data members) to be referred to by a single name.

- **Object**: A struct variable is called an object.
- **Data Members**: The components inside the struct.
- **Access Specifier**: Struct members are `public` by default (accessible by any function), whereas Class members are `private` by default.

**General Convention**: Use structs when there are no member functions. Use classes when there are member functions.

### Definition
```cpp
struct Time {
    int hours;
    int minutes;
    int seconds;
}; // Semicolon is required
```

### Usage
```cpp
struct Date {
    int month;
    int day;
    int year;
};

int main() {
    // Initialization list
    Date today = {3, 1, 2018}; 
    
    // Variable declaration
    Date payDay; 
    
    // Dot Notation to access members
    payDay.month = 3;
    payDay.day = 1;
    payDay.year = 2018;
    
    if (today.month == payDay.month && today.day == payDay.day && today.year == payDay.year) {
        cout << "Today is pay day!";
    }
}
```

### Passing Structs to Functions
Passed by reference to avoid copying.

```cpp
void getDate(Date & date);

int main() {
    Date today;
    getDate(today);
    return 0;
}

void getDate(Date & date) {
    cout << "Enter the date (mmddyy): ";
    cin >> date.month >> date.day >> date.year;
}
```

## Accessing Data Members
There are two ways to access struct members:

1.  **Dot Operator (.)**: Used with objects.
    ```cpp
    Box tackleBox;
    tackleBox.width = 10;
    ```
2.  **Arrow Operator (->)**: Used with pointers to objects.
    ```cpp
    Box shoeBox;
    Box *ptr = &shoeBox;
    ptr->width = 10; // Equivalent to (*ptr).width
    ```

### Example with Pointers
```cpp
struct Box {
    int width;
    int height;
    int length;
};

int main() {
    Box * ptr;
    Box toolBox = {9, 12, 18};
    Box shoeBox = {7, 6, 12};
    
    ptr = &shoeBox;
    
    cout << "Toolbox: " << toolBox.width << "-" << toolBox.height << "-" << toolBox.length << endl;
    cout << "Shoebox: " << ptr->width << "-" << ptr->height << "-" << ptr->length << endl;
    
    return 0;
}
```

## Constructors in Structs
A struct can have a constructor to initialize data members.

```cpp
struct Box {
    int width;
    int height;
    int length;
    
    // Constructor
    Box() {
        width = 0;
        height = 0;
        length = 0;
    }
};
```

## Array of Struct Objects
An array can hold struct objects.

```cpp
struct Record {
    string name;
    int age;
};

const int SIZE = 5;

int main() {
    Record records[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "AGE: ";
        cin >> records[i].age;
        cin.ignore();
        cout << "NAME: ";
        getline(cin, records[i].name);
    }
}
```

## Header Files
Programmer-defined header files (e.g., `Box.h`) can hold struct definitions.
Use `#include "Box.h"` (quotes for local files) to include them.

