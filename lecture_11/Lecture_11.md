# Lecture #11: Classes and Objects

## Classes Overview
A **class** is a user-defined data type that bundles data (attributes) and functions (methods) together. It's the foundation of Object-Oriented Programming (OOP).

- **Object**: An instance of a class (like a struct variable is called an object)
- **Data Members**: Variables inside the class (attributes)
- **Member Functions**: Functions inside the class (methods)
- **Access Specifier**: Class members are `private` by default, whereas Struct members are `public` by default

**General Convention**: Use structs for simple data grouping without methods. Use classes when you have member functions and need encapsulation.

### Class vs Struct
| Feature | Class | Struct |
|---------|-------|--------|
| Default access | `private` | `public` |
| Use when | Have member functions | Simple data grouping |
| Encapsulation | Better data protection | Less protection |

## Class Definition

```cpp
class Student {
private:           // Access specifier (optional - private by default)
    string name;   // Data members
    int id;
    double gpa;

public:            // Access specifier
    // Member functions go here
}; // Semicolon required!
```

## Access Specifiers

### Private
- Only accessible by member functions of the same class
- Data members should typically be `private` (encapsulation)
- Cannot be accessed directly from outside the class

### Public
- Accessible from anywhere in the program
- Member functions that need to be called externally should be `public`
- Provides the "interface" to the class

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

## Member Functions
Member functions can access all class members (both private and public). They are the interface through which outside code interacts with private data.

### Defining Inside the Class (Inline)
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
```

### Defining Outside the Class
Use the **scope resolution operator** `::` to define member functions outside the class:

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

### Calling Member Functions
```cpp
Student s;
s.setName("Alice");           // Use dot operator
cout << s.getName() << endl;  // Outputs: Alice
```

## Constructors
A **constructor** is a special member function that initializes an object when it's created.

**Constructor Rules**:
- Same name as the class
- No return type (not even `void`)
- Called automatically when object is created
- Can be overloaded (multiple constructors)

### Default Constructor
```cpp
class Student {
private:
    string name;
    int id;
    double gpa;
public:
    Student() {           // Default constructor
        name = "Unknown";
        id = 0;
        gpa = 0.0;
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

Student s("Bob", 12345, 3.8);  // Pass arguments to constructor
```

### Constructor Overloading
Multiple constructors with different parameters:

```cpp
class Student {
public:
    Student() {                         // Default
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }
    Student(string n) {                 // Name only
        name = n;
        id = 0;
        gpa = 0.0;
    }
    Student(string n, int i, double g) { // All parameters
        name = n;
        id = i;
        gpa = g;
    }
};

Student s1;                    // Calls default
Student s2("Alice");           // Calls single-param
Student s3("Bob", 123, 3.9);   // Calls three-param
```

### Member Initializer List (Preferred)
More efficient initialization syntax:

```cpp
class Student {
public:
    Student(string n, int i, double g) 
        : name(n), id(i), gpa(g) {  // Initializer list
        // Constructor body (can be empty)
    }
};
```

## Accessor and Mutator Functions

### Accessor (Getter)
Returns the value of a private member:

```cpp
string getName() {
    return name;
}

double getGpa() {
    return gpa;
}
```

### Mutator (Setter)
Sets the value of a private member. Can include validation:

```cpp
void setName(string n) {
    name = n;
}

void setGpa(double g) {
    if (g >= 0.0 && g <= 4.0) {  // Validation!
        gpa = g;
    } else {
        cout << "Invalid GPA!" << endl;
    }
}
```

### Complete Example
```cpp
class Student {
private:
    string name;
    int id;
    double gpa;
    
public:
    // Constructor
    Student() : name(""), id(0), gpa(0.0) {}
    
    // Mutators (setters)
    void setName(string n) { name = n; }
    void setId(int i) { id = i; }
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
    }
    
    // Accessors (getters)
    string getName() { return name; }
    int getId() { return id; }
    double getGpa() { return gpa; }
    
    // Display function
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
    }
};
```

## Array of Objects
Just like arrays of primitive types, you can create arrays of objects:

```cpp
const int SIZE = 3;
Student students[SIZE];  // Array of 3 Student objects

// Set data using loop
for (int i = 0; i < SIZE; i++) {
    string name;
    int id;
    double gpa;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter GPA: ";
    cin >> gpa;
    cin.ignore();  // Clear newline
    
    students[i].setName(name);
    students[i].setId(id);
    students[i].setGpa(gpa);
}

// Display all
for (int i = 0; i < SIZE; i++) {
    cout << "\nStudent " << i + 1 << ":" << endl;
    students[i].displayInfo();
}
```

## Objects as Function Parameters

### Pass by Reference (Recommended)
Use `&` to avoid copying the entire object:

```cpp
void displayStudent(Student &s) {
    cout << s.getName() << " - GPA: " << s.getGpa() << endl;
}

Student student("Alice", 123, 3.9);
displayStudent(student);  // No '&' in call
```

### Pass by Const Reference (Best Practice)
Use `const` when the function doesn't modify the object:

```cpp
void displayStudent(const Student &s) {
    // Can only call const member functions
    cout << s.getName() << endl;
}
```

**Note**: Accessor functions should be marked `const`:
```cpp
string getName() const { return name; }  // Const member function
```

## The `this` Pointer
Every member function has an implicit pointer `this` that points to the object calling the function:

```cpp
class Student {
private:
    string name;
public:
    void setName(string name) {
        this->name = name;  // Disambiguate parameter from member
    }
};
```

## Encapsulation Benefits
1. **Data Protection**: Private members can't be accidentally modified
2. **Validation**: Setters can validate input before storing
3. **Abstraction**: Hide implementation details
4. **Maintainability**: Can change internal implementation without affecting external code

## Common Mistakes to Avoid

1. **Trying to access private members directly**
   ```cpp
   Student s;
   s.name = "Bob";  // ERROR: 'name' is private
   s.setName("Bob"); // Correct
   ```

2. **Giving constructor a return type**
   ```cpp
   void Student() { }  // WRONG - constructors have no return type
   Student() { }       // Correct
   ```

3. **Forgetting semicolon after class definition**
   ```cpp
   class Student {
   }   // WRONG - missing semicolon
   };  // Correct
   ```

4. **Passing objects by value (inefficient)**
   ```cpp
   void func(Student s) { }       // Copies entire object
   void func(const Student &s) { } // Pass by reference (efficient)
   ```

## Design Best Practices

1. **Make data members `private`** - Always encapsulate data
2. **Provide `public` interface** - Use accessors/mutators
3. **Use constructors** - Initialize all members
4. **Add validation** - Validate input in mutators
5. **Use `const`** - Mark read-only functions as `const`
6. **Pass by `const` reference** - Avoid unnecessary copies

## Quick Reference

```cpp
class ClassName {
private:
    // Data members (attributes)
    Type member1;
    Type member2;

public:
    // Constructor(s)
    ClassName();
    ClassName(Type param1, Type param2);
    
    // Accessors (getters)
    Type getMember1() const;
    
    // Mutators (setters)
    void setMember1(Type value);
    
    // Other member functions
    void display() const;
};
```

## Next Steps
After mastering classes and objects, you'll learn:
- **Inheritance**: Creating new classes from existing ones
- **Polymorphism**: Objects behaving differently based on type
- **Operator Overloading**: Defining custom behavior for operators
- **Dynamic Memory**: Using `new` and `delete` with objects
