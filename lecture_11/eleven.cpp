/*
 * Lecture 11 Learning Template - Classes and Objects
 * 
 * INSTRUCTIONS:
 * This is a guided learning file. Follow the comments in each section to
 * write the code yourself. Uncomment sections in main() as you complete them.
 * Compile and run to test your work!
 */

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes

// Section 1: Class Basics
void demonstrateClassBasics();

// Section 2: Private vs Public Access Specifiers
void demonstrateAccessSpecifiers();

// Section 3: Member Functions
void demonstrateMemberFunctions();

// Section 4: Constructors
void demonstrateConstructors();

// Section 5: Multiple Constructors (Overloading)
void demonstrateConstructorOverloading();

// Section 6: Accessor and Mutator Functions
void demonstrateAccessorsMutators();

// Section 7: Array of Objects
void demonstrateObjectArray();

// Section 8: Objects as Function Parameters
void displayStudent(const class Student &);
void demonstrateObjectParameters();

// Class Definitions (place before functions that use them)

// Basic Student class for examples
class Student {
    // TODO: Add private members (name, id, gpa)
    
public:
    // TODO: Add public member functions
};

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    cout << "========================================" << endl;
    cout << "  LECTURE 11 LEARNING TEMPLATE" << endl;
    cout << "========================================" << endl;
    
    // TODO: Uncomment sections as you complete them to test your code:
    
    // demonstrateClassBasics();          // Section 1: Class basics
    // demonstrateAccessSpecifiers();     // Section 2: Private vs public
    // demonstrateMemberFunctions();      // Section 3: Member functions
    // demonstrateConstructors();         // Section 4: Constructors
    // demonstrateConstructorOverloading(); // Section 5: Multiple constructors
    // demonstrateAccessorsMutators();    // Section 6: Accessors and mutators
    // demonstrateObjectArray();         // Section 7: Array of objects
    // demonstrateObjectParameters();     // Section 8: Objects as parameters
    
    cout << "\n========================================" << endl;
    cout << "  Remember to uncomment sections in main() to test!" << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}

// ============================================================================
// SECTION 1: CLASS BASICS
// ============================================================================
/*
 * TASK: Define a simple class and create an object
 * 
 * STEPS:
 * 1. Define a class called Student (above main):
 *    class Student {
 *    private:
 *        string name;
 *        int id;
 *        double gpa;
 *    
 *    public:
 *        // We'll add functions in later sections
 *    };
 * 
 * 2. In this function, create a Student object:
 *    - Student student1;
 * 
 * 3. Try to access members directly:
 *    - student1.name = "John";  // This will cause an error!
 *    - Note: Private members cannot be accessed directly
 * 
 * 4. Output: "Class created successfully"
 *    - Comment out the direct access line since it won't compile
 * 
 * REMEMBER:
 * - Class is similar to struct but members are private by default
 * - Use classes when you have member functions
 * - Private members can only be accessed by member functions
 */
void demonstrateClassBasics() {
    cout << "\n=== SECTION 1: Class Basics ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 2: PRIVATE VS PUBLIC ACCESS SPECIFIERS
// ============================================================================
/*
 * TASK: Understand the difference between private and public
 * 
 * STEPS:
 * 1. Define a class with both private and public sections:
 *    class Student {
 *    private:
 *        string name;      // Cannot be accessed directly
 *        int id;           // Cannot be accessed directly
 *    
 *    public:
 *        double gpa;       // Can be accessed directly
 *    };
 * 
 * 2. Create a Student object:
 *    - Student student1;
 * 
 * 3. Try accessing public member:
 *    - student1.gpa = 3.5;  // This works!
 *    - Output: "Public member gpa: " followed by student1.gpa
 * 
 * 4. Try accessing private member (will cause error):
 *    - student1.name = "John";  // Error - comment this out
 *    - Output: "Cannot access private member 'name' directly"
 * 
 * REMEMBER:
 * - private: Only accessible by member functions
 * - public: Accessible from anywhere
 * - Default access in class is private
 * - Default access in struct is public
 */
void demonstrateAccessSpecifiers() {
    cout << "\n=== SECTION 2: Private vs Public Access Specifiers ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 3: MEMBER FUNCTIONS
// ============================================================================
/*
 * TASK: Add member functions to a class
 * 
 * STEPS:
 * 1. Define a class with member functions:
 *    class Student {
 *    private:
 *        string name;
 *        int id;
 *        double gpa;
 *    
 *    public:
 *        void setName(string n) {
 *            name = n;
 *        }
 *        
 *        void displayInfo() {
 *            cout << "Name: " << name << endl;
 *            cout << "ID: " << id << endl;
 *            cout << "GPA: " << gpa << endl;
 *        }
 *    };
 * 
 * 2. Create a Student object:
 *    - Student student1;
 * 
 * 3. Call member function to set name:
 *    - student1.setName("Alice");
 * 
 * 4. Call member function to display:
 *    - student1.displayInfo();
 * 
 * REMEMBER:
 * - Member functions can access private members
 * - Call using object.functionName()
 * - Functions defined inside class are inline by default
 */
void demonstrateMemberFunctions() {
    cout << "\n=== SECTION 3: Member Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 4: CONSTRUCTORS
// ============================================================================
/*
 * TASK: Add a constructor to initialize objects
 * 
 * STEPS:
 * 1. Define a class with constructor:
 *    class Student {
 *    private:
 *        string name;
 *        int id;
 *        double gpa;
 *    
 *    public:
 *        // Constructor - same name as class
 *        Student() {
 *            name = "Unknown";
 *            id = 0;
 *            gpa = 0.0;
 *        }
 *        
 *        void displayInfo() {
 *            // Display function
 *        }
 *    };
 * 
 * 2. Create Student object (constructor called automatically):
 *    - Student student1;
 * 
 * 3. Display info:
 *    - student1.displayInfo();
 *    - Should show default values
 * 
 * REMEMBER:
 * - Constructor has same name as class
 * - No return type (not even void)
 * - Called automatically when object is created
 * - Used to initialize data members
 */
void demonstrateConstructors() {
    cout << "\n=== SECTION 4: Constructors ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 5: MULTIPLE CONSTRUCTORS (OVERLOADING)
// ============================================================================
/*
 * TASK: Create multiple constructors with different parameters
 * 
 * STEPS:
 * 1. Define a class with multiple constructors:
 *    class Student {
 *    private:
 *        string name;
 *        int id;
 *        double gpa;
 *    
 *    public:
 *        // Default constructor
 *        Student() {
 *            name = "Unknown";
 *            id = 0;
 *            gpa = 0.0;
 *        }
 *        
 *        // Constructor with parameters
 *        Student(string n, int i, double g) {
 *            name = n;
 *            id = i;
 *            gpa = g;
 *        }
 *        
 *        void displayInfo() {
 *            // Display function
 *        }
 *    };
 * 
 * 2. Create objects using different constructors:
 *    - Student student1;  // Uses default constructor
 *    - Student student2("Bob", 12345, 3.8);  // Uses parameterized constructor
 * 
 * 3. Display both:
 *    - student1.displayInfo();
 *    - student2.displayInfo();
 * 
 * REMEMBER:
 * - Can have multiple constructors (function overloading)
 * - Constructor called depends on arguments provided
 * - Default constructor has no parameters
 */
void demonstrateConstructorOverloading() {
    cout << "\n=== SECTION 5: Multiple Constructors (Overloading) ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 6: ACCESSOR AND MUTATOR FUNCTIONS
// ============================================================================
/*
 * TASK: Create getter and setter functions
 * 
 * STEPS:
 * 1. Define a class with accessors and mutators:
 *    class Student {
 *    private:
 *        string name;
 *        int id;
 *        double gpa;
 *    
 *    public:
 *        // Mutator (setter) functions
 *        void setName(string n) { name = n; }
 *        void setId(int i) { id = i; }
 *        void setGpa(double g) { gpa = g; }
 *        
 *        // Accessor (getter) functions
 *        string getName() { return name; }
 *        int getId() { return id; }
 *        double getGpa() { return gpa; }
 *    };
 * 
 * 2. Create a Student object:
 *    - Student student1;
 * 
 * 3. Use mutators to set values:
 *    - student1.setName("Charlie");
 *    - student1.setId(67890);
 *    - student1.setGpa(3.9);
 * 
 * 4. Use accessors to get and display values:
 *    - Output: "Name: " followed by student1.getName()
 *    - Output: "ID: " followed by student1.getId()
 *    - Output: "GPA: " followed by student1.getGpa()
 * 
 * REMEMBER:
 * - Accessor (getter): Returns value of private member
 * - Mutator (setter): Sets value of private member
 * - Provides controlled access to private data
 * - Can add validation in mutators
 */
void demonstrateAccessorsMutators() {
    cout << "\n=== SECTION 6: Accessor and Mutator Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 7: ARRAY OF OBJECTS
// ============================================================================
/*
 * TASK: Create and use an array of objects
 * 
 * STEPS:
 * 1. Assume Student class is defined with appropriate constructors/functions
 * 
 * 2. Declare const int SIZE = 3;
 * 3. Declare array: Student students[SIZE];
 * 
 * 4. Use a loop to set data for each student:
 *    - Loop from i = 0 to i < SIZE
 *    - Prompt: "Enter name for student " followed by i+1, ": "
 *    - Read name into a string variable
 *    - Prompt: "Enter ID: "
 *    - Read ID
 *    - Prompt: "Enter GPA: "
 *    - Read GPA
 *    - Use mutators: students[i].setName(...), etc.
 * 
 * 5. Use another loop to display all students:
 *    - Loop from i = 0 to i < SIZE
 *    - Output: "Student " followed by i+1, ":"
 *    - Call: students[i].displayInfo(); or use accessors
 * 
 * REMEMBER:
 * - Each array element is an object
 * - Use array[index].memberFunction() to call functions
 * - Useful for managing multiple objects
 */
void demonstrateObjectArray() {
    cout << "\n=== SECTION 7: Array of Objects ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 8: OBJECTS AS FUNCTION PARAMETERS
// ============================================================================
/*
 * TASK: Pass objects to functions
 * 
 * STEP 1 - Write helper function displayStudent():
 *    - Parameter: const Student &student (const reference)
 *    - Use accessors to display student info:
 *      Output: "Name: " followed by student.getName()
 *      Output: "ID: " followed by student.getId()
 *      Output: "GPA: " followed by student.getGpa()
 * 
 * STEP 2 - In demonstrateObjectParameters():
 *    1. Create a Student object:
 *       - Student student1("David", 11111, 4.0);
 *    
 *    2. Call the function:
 *       - displayStudent(student1);
 * 
 * REMEMBER:
 * - Pass by reference (&) to avoid copying
 * - Use const if function doesn't modify object
 * - More efficient than pass by value
 */
void displayStudent(const Student &student) {
    // TODO: Implement this function
    // Use accessor functions to display student information
    
}

void demonstrateObjectParameters() {
    cout << "\n=== SECTION 8: Objects as Function Parameters ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

