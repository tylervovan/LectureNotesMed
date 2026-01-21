# Lecture 11: Learning Instructions - Classes and Objects

## Overview
This guide will help you learn classes, objects, encapsulation, constructors, and object-oriented programming basics.

## Prerequisites
- Understanding of structs (from Lecture 10)
- Knowledge of functions and parameters
- Understanding of arrays

## How to Use This Template

1. **Open** `eleven.cpp` in your IDE
2. **Read** the instructions in each function's comment block
3. **Write** the code following the step-by-step instructions
4. **Uncomment** the function call in `main()` to test your code
5. **Compile** and **run** to verify your implementation

## Section-by-Section Guide

### Section 1: Class Basics
**Learning Goal**: Understand the difference between classes and structs

**Key Concepts**:
- Class is similar to struct but members are `private` by default
- Use classes when you have member functions
- Private members cannot be accessed directly from outside the class

**Important Notes**:
- Default access in class is `private`
- Default access in struct is `public`
- Classes provide better data protection (encapsulation)

**Common Mistakes**:
- Trying to access private members directly (will cause error)
- Forgetting that classes need member functions to access private data
- Confusing class definition with object creation

**Comparison**:
```cpp
struct Student {    // Public by default
    string name;
};

class Student {     // Private by default
    string name;    // Cannot access directly!
public:
    // Need public functions to access name
};
```

---

### Section 2: Private vs Public Access Specifiers
**Learning Goal**: Understand access control in classes

**Key Concepts**:
- `private`: Only accessible by member functions of the class
- `public`: Accessible from anywhere in the program
- Use `private` to protect data, `public` for interface

**Important Notes**:
- Data members should typically be `private`
- Member functions that need to be called from outside should be `public`
- Access specifiers control encapsulation

**Common Mistakes**:
- Making everything public (defeats purpose of encapsulation)
- Trying to access private members from outside class
- Not understanding which members should be private vs public

**Best Practice**:
```cpp
class Student {
private:
    string name;    // Data hidden
    int id;
    
public:
    void setName(string n);  // Interface to modify data
    string getName();        // Interface to access data
};
```

---

### Section 3: Member Functions
**Learning Goal**: Add functions that belong to the class

**Key Concepts**:
- Member functions can access private members
- Called using `object.functionName()`
- Functions defined inside class are inline by default

**Important Notes**:
- Member functions have access to all class members (private and public)
- Can be defined inside or outside the class
- Use member functions to manipulate private data

**Common Mistakes**:
- Forgetting to use object when calling: `functionName()` instead of `obj.functionName()`
- Not understanding scope of member functions
- Trying to access private members from non-member functions

**Example**:
```cpp
class Student {
private:
    string name;
public:
    void setName(string n) {
        name = n;  // Can access private member!
    }
};

Student s;
s.setName("Alice");  // Correct way to call
```

---

### Section 4: Constructors
**Learning Goal**: Initialize objects automatically when created

**Key Concepts**:
- Constructor has same name as class
- No return type (not even `void`)
- Called automatically when object is created
- Used to initialize data members

**Important Notes**:
- Constructor runs when object is declared
- If no constructor defined, compiler provides default (does nothing)
- Can initialize members to default values

**Common Mistakes**:
- Giving constructor a return type
- Forgetting constructor name must match class name exactly
- Not understanding when constructor is called

**Example**:
```cpp
class Student {
private:
    string name;
    int id;
public:
    Student() {           // Constructor
        name = "Unknown";
        id = 0;
    }
};

Student s;  // Constructor called automatically
```

---

### Section 5: Multiple Constructors (Overloading)
**Learning Goal**: Create objects in different ways

**Key Concepts**:
- Can have multiple constructors (function overloading)
- Constructor called depends on arguments provided
- Default constructor has no parameters

**Important Notes**:
- Different constructors for different initialization needs
- Compiler chooses constructor based on arguments
- Can have default values in parameters

**Common Mistakes**:
- Having ambiguous constructors (compiler can't decide)
- Not providing default constructor when needed
- Confusing constructor calls

**Example**:
```cpp
class Student {
public:
    Student() {                    // Default constructor
        name = "Unknown";
    }
    Student(string n) {            // Parameterized constructor
        name = n;
    }
};

Student s1;              // Calls default constructor
Student s2("Bob");       // Calls parameterized constructor
```

---

### Section 6: Accessor and Mutator Functions
**Learning Goal**: Provide controlled access to private data

**Key Concepts**:
- **Accessor (getter)**: Returns value of private member
- **Mutator (setter)**: Sets value of private member
- Provides controlled access with validation possible

**Important Notes**:
- Accessors typically have `get` prefix: `getName()`
- Mutators typically have `set` prefix: `setName()`
- Can add validation in mutators before setting values

**Common Mistakes**:
- Not using accessors/mutators and trying to access private members directly
- Forgetting return type in accessor
- Not validating input in mutators

**Best Practice**:
```cpp
class Student {
private:
    double gpa;
public:
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {  // Validation!
            gpa = g;
        }
    }
    double getGpa() {
        return gpa;
    }
};
```

---

### Section 7: Array of Objects
**Learning Goal**: Manage multiple objects efficiently

**Key Concepts**:
- Each array element is an object
- Use `array[index].memberFunction()` to call functions
- Useful for managing collections of objects

**Important Notes**:
- `students[i]` is a Student object
- Can call member functions: `students[i].getName()`
- Loop through array to process all objects

**Common Mistakes**:
- Forgetting dot operator when calling member functions
- Going out of array bounds
- Not initializing objects properly

**Example**:
```cpp
Student students[5];
for (int i = 0; i < 5; i++) {
    students[i].setName("Student " + to_string(i));
    cout << students[i].getName() << endl;
}
```

---

### Section 8: Objects as Function Parameters
**Learning Goal**: Pass objects to functions efficiently

**Key Concepts**:
- Pass by reference using `&` to avoid copying
- Use `const` if function doesn't modify object
- More efficient than pass-by-value

**Important Notes**:
- Use `&` in parameter: `void func(const Student &s)`
- Call normally: `func(student)` (no `&` needed)
- `const` prevents accidental modification

**Common Mistakes**:
- Passing by value (creates copy, wastes memory)
- Forgetting `const` when function shouldn't modify
- Using `&` in function call (don't need it)

**Example**:
```cpp
void displayStudent(const Student &s) {  // const reference
    cout << s.getName() << endl;        // Can read but not modify
}

Student s("Alice");
displayStudent(s);  // Pass object, not address
```

---

## Key Concepts Summary

### Class vs Struct
| Feature | Class | Struct |
|---------|-------|--------|
| Default access | `private` | `public` |
| Use when | Have member functions | Simple data grouping |
| Encapsulation | Better | Less |

### Access Specifiers
- **`private`**: Data members (hidden from outside)
- **`public`**: Member functions (interface to outside)

### Constructor Rules
- Same name as class
- No return type
- Called automatically
- Can be overloaded

### Member Functions
- Can access private members
- Called with `object.function()`
- Provide interface to class

---

## Practice Exercises

After completing all sections, try these challenges:

1. **Bank Account Class**: Create a class with balance (private), deposit/withdraw functions, and getBalance accessor
2. **Rectangle Class**: Create a class with width/height, calculate area/perimeter, with validation
3. **Student Manager**: Create Student class, array of students, functions to find highest GPA, average GPA
4. **Library System**: Create Book class with title/author, Library class that manages array of books

## Troubleshooting

**Compilation Errors**:
- "incomplete type" → Make sure class is defined before use
- "cannot access private member" → Use accessor/mutator functions
- "no matching function" → Check constructor parameters match

**Runtime Errors**:
- Program crashes → Check if object is initialized
- Wrong values → Verify accessor/mutator functions
- Unexpected behavior → Check if using const correctly

**Logic Errors**:
- Changes not working → Check if passing by value instead of reference
- Wrong data → Verify mutator validation logic
- Can't access data → Remember to use accessor functions

## Object-Oriented Programming Principles

1. **Encapsulation**: Hide data, provide interface
2. **Data Protection**: Private members prevent direct access
3. **Abstraction**: Hide implementation details
4. **Reusability**: Classes can be reused in different programs

## Design Tips

- Make data members `private`
- Provide `public` interface through member functions
- Use constructors for initialization
- Use accessors/mutators for controlled access
- Add validation in mutators
- Use `const` for functions that don't modify

## Next Steps

Once you've mastered Lecture 11, you'll be ready for:
- More advanced OOP concepts (inheritance, polymorphism)
- File I/O with objects
- Dynamic memory allocation with classes
- Building larger programs with multiple classes

