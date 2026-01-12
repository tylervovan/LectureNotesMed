/*
 * Lecture 10 Learning Template - Pointers, Dot Operator, and Struct
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

// Section 1: Pointer Basics
void demonstratePointers();

// Section 2: Address Operator (&) and De-reference Operator (*)
void demonstrateAddressAndDereference();

// Section 3: Pointers and Arrays
void demonstratePointersAndArrays();

// Section 4: Pointers as Function Parameters
void getName(char *);
void displayName(char *);
void demonstratePointersAsParameters();

// Section 5: Struct Basics
void demonstrateStructBasics();

// Section 6: Struct with Dot Operator
void demonstrateStructDotOperator();

// Section 7: Struct with Arrow Operator (->)
void demonstrateStructArrowOperator();

// Section 8: Passing Structs to Functions
void getDate(struct Date &);
void demonstrateStructPassing();

// Section 9: Struct Constructors
void demonstrateStructConstructors();

// Section 10: Array of Struct Objects
void demonstrateStructArray();

// Struct Definitions (place before functions that use them)
struct Date {
    int month;
    int day;
    int year;
};

struct Box {
    int width;
    int height;
    int length;
};

struct Record {
    string name;
    int age;
};

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    cout << "========================================" << endl;
    cout << "  LECTURE 10 LEARNING TEMPLATE" << endl;
    cout << "========================================" << endl;
    
    // TODO: Uncomment sections as you complete them to test your code:
    
    // demonstratePointers();              // Section 1: Pointer basics
    // demonstrateAddressAndDereference(); // Section 2: & and * operators
    // demonstratePointersAndArrays();     // Section 3: Pointers with arrays
    // demonstratePointersAsParameters();  // Section 4: Pointers as parameters
    // demonstrateStructBasics();          // Section 5: Struct basics
    // demonstrateStructDotOperator();     // Section 6: Dot operator
    // demonstrateStructArrowOperator();   // Section 7: Arrow operator
    // demonstrateStructPassing();         // Section 8: Passing structs
    // demonstrateStructConstructors();    // Section 9: Struct constructors
    // demonstrateStructArray();          // Section 10: Array of structs
    
    cout << "\n========================================" << endl;
    cout << "  Remember to uncomment sections in main() to test!" << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}

// ============================================================================
// SECTION 1: POINTER BASICS
// ============================================================================
/*
 * TASK: Learn how to declare and initialize pointers
 * 
 * STEPS:
 * 1. Declare a char variable: char initial = 'T';
 * 
 * 2. Declare a pointer to char (three ways are valid):
 *    - char *charPtr;
 *    - char* charPtr;
 *    - char * charPtr;
 *    (Choose one style and be consistent)
 * 
 * 3. Assign the address of 'initial' to the pointer:
 *    - charPtr = &initial;
 * 
 * 4. Output the address stored in the pointer:
 *    - Output: "Address of initial: " followed by charPtr
 *    - Note: This will show a memory address (hexadecimal number)
 * 
 * 5. Declare and initialize a pointer in one line:
 *    - char *anotherPtr = &initial;
 * 
 * REMEMBER:
 * - A pointer holds a memory address, not a value
 * - Use & to get the address of a variable
 * - The asterisk (*) must be in front of each pointer variable name
 */
void demonstratePointers() {
    cout << "\n=== SECTION 1: Pointer Basics ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 2: ADDRESS OPERATOR (&) AND DE-REFERENCE OPERATOR (*)
// ============================================================================
/*
 * TASK: Learn how to use & to get addresses and * to access values
 * 
 * STEPS:
 * 1. Declare a double variable: double deposit;
 * 2. Declare a pointer: double *ptr;
 * 3. Assign address: ptr = &deposit;
 * 
 * 4. Use de-reference operator to assign a value:
 *    - *ptr = 1050.0;  // This assigns 1050.0 to deposit
 * 
 * 5. Output the value two ways:
 *    - Output: "Value via variable: " followed by deposit
 *    - Output: "Value via pointer: " followed by *ptr
 *    (Both should show 1050.0)
 * 
 * 6. Change the value through the pointer:
 *    - *ptr = 2000.0;
 *    - Output: "After changing via pointer, deposit = " followed by deposit
 * 
 * REMEMBER:
 * - & gets the address of a variable
 * - * (when used with a pointer) accesses the value at that address
 * - *ptr means "the value that ptr points to"
 */
void demonstrateAddressAndDereference() {
    cout << "\n=== SECTION 2: Address (&) and De-reference (*) Operators ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 3: POINTERS AND ARRAYS
// ============================================================================
/*
 * TASK: Use pointers to iterate through an array
 * 
 * STEPS:
 * 1. Declare const int SIZE = 5;
 * 2. Declare an array: int numbers[SIZE] = {6, 8, 9, 3, 7};
 * 3. Declare a pointer: int *ptr;
 * 
 * 4. Assign pointer to first element:
 *    - ptr = numbers;  // This assigns address of numbers[0] to ptr
 *    - Note: You can also use: ptr = &numbers[0];
 * 
 * 5. Use a loop to print all array elements using the pointer:
 *    - Loop from i = 0 to i < SIZE
 *    - Output: *ptr followed by endl
 *    - Increment pointer: ptr++;
 *    - Note: ptr++ moves to the next element (adds sizeof(int) bytes)
 * 
 * 6. Output: "Array accessed via pointer arithmetic"
 * 
 * REMEMBER:
 * - Array name without [] gives the address of the first element
 * - ptr++ increments by the size of the data type (4 bytes for int)
 * - You can use pointer arithmetic to traverse arrays
 */
void demonstratePointersAndArrays() {
    cout << "\n=== SECTION 3: Pointers and Arrays ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 4: POINTERS AS FUNCTION PARAMETERS
// ============================================================================
/*
 * TASK: Pass pointers to functions to modify original variables
 * 
 * STEP 1 - Write helper function getName():
 *    - Parameter: char *pName (pointer to char)
 *    - Prompt: "Enter name: "
 *    - Read: cin.getline(pName, 30);
 *    - Note: pName points to the original array, so changes persist
 * 
 * STEP 2 - Write helper function displayName():
 *    - Parameter: char *pName
 *    - Output: "Hi " followed by pName followed by ".\n"
 * 
 * STEP 3 - In demonstratePointersAsParameters():
 *    1. Declare const int SIZE = 30;
 *    2. Declare: char name[SIZE];
 *    3. Declare: char *ptr = name;  // ptr points to name[0]
 *    4. Call: getName(ptr);
 *    5. Call: displayName(ptr);
 * 
 * REMEMBER:
 * - Passing a pointer gives the function access to the original variable
 * - Changes made through the pointer affect the original
 * - This is similar to pass-by-reference
 */
void getName(char *pName) {
    // TODO: Implement this function
    // Prompt for name and read into pName using cin.getline()
    
}

void displayName(char *pName) {
    // TODO: Implement this function
    // Display "Hi " followed by the name
    
}

void demonstratePointersAsParameters() {
    cout << "\n=== SECTION 4: Pointers as Function Parameters ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 5: STRUCT BASICS
// ============================================================================
/*
 * TASK: Define and use a struct
 * 
 * STEPS:
 * 1. The Date struct is already defined above main()
 * 
 * 2. Create a Date object using initialization list:
 *    - Date today = {3, 1, 2018};
 *    - Output: "Today: " followed by today.month, today.day, today.year
 * 
 * 3. Create another Date object:
 *    - Date payDay;
 * 
 * 4. Assign values using dot operator:
 *    - payDay.month = 3;
 *    - payDay.day = 1;
 *    - payDay.year = 2018;
 *    - Output: "Pay day: " followed by payDay.month, payDay.day, payDay.year
 * 
 * 5. Compare the dates:
 *    - Use if statement to check if today equals payDay
 *    - Output: "Today is pay day!" if they match
 * 
 * REMEMBER:
 * - Struct is a collection of related data members
 * - Struct members are public by default
 * - Use dot operator (.) to access members
 * - Semicolon required after struct definition
 */
void demonstrateStructBasics() {
    cout << "\n=== SECTION 5: Struct Basics ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 6: STRUCT WITH DOT OPERATOR
// ============================================================================
/*
 * TASK: Access struct members using the dot operator
 * 
 * STEPS:
 * 1. The Box struct is already defined above main()
 * 
 * 2. Create a Box object using initialization list:
 *    - Box toolBox = {9, 12, 18};
 * 
 * 3. Access and display members using dot operator:
 *    - Output: "Toolbox dimensions (W-H-L): "
 *    - Output: toolBox.width, "-", toolBox.height, "-", toolBox.length
 * 
 * 4. Create another Box and assign values individually:
 *    - Box shoeBox;
 *    - shoeBox.width = 7;
 *    - shoeBox.height = 6;
 *    - shoeBox.length = 12;
 * 
 * 5. Display shoebox dimensions:
 *    - Output: "Shoebox dimensions (W-H-L): "
 *    - Output: shoeBox.width, "-", shoeBox.height, "-", shoeBox.length
 * 
 * REMEMBER:
 * - Dot operator (.) is used with objects (not pointers)
 * - object.member accesses the member
 */
void demonstrateStructDotOperator() {
    cout << "\n=== SECTION 6: Struct with Dot Operator ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 7: STRUCT WITH ARROW OPERATOR (->)
// ============================================================================
/*
 * TASK: Access struct members using pointers and arrow operator
 * 
 * STEPS:
 * 1. The Box struct is already defined above main()
 * 
 * 2. Create Box objects:
 *    - Box toolBox = {9, 12, 18};
 *    - Box shoeBox = {7, 6, 12};
 * 
 * 3. Declare a pointer to Box:
 *    - Box *ptr;
 * 
 * 4. Assign address of shoeBox to pointer:
 *    - ptr = &shoeBox;
 * 
 * 5. Display toolBox using dot operator:
 *    - Output: "Toolbox: " followed by dimensions
 * 
 * 6. Display shoeBox using arrow operator:
 *    - Output: "Shoebox: " followed by ptr->width, ptr->height, ptr->length
 *    - Note: ptr->width is equivalent to (*ptr).width
 * 
 * 7. Change a value through the pointer:
 *    - ptr->width = 10;
 *    - Output: "After change, shoebox width: " followed by shoeBox.width
 * 
 * REMEMBER:
 * - Arrow operator (->) is used with pointers to objects
 * - ptr->member is shorthand for (*ptr).member
 * - Changes through pointer affect the original object
 */
void demonstrateStructArrowOperator() {
    cout << "\n=== SECTION 7: Struct with Arrow Operator (->) ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 8: PASSING STRUCTS TO FUNCTIONS
// ============================================================================
/*
 * TASK: Pass structs to functions by reference
 * 
 * STEP 1 - Write helper function getDate():
 *    - Parameter: Date &date (reference parameter)
 *    - Prompt: "Enter the date (mmddyy): "
 *    - Read: cin >> date.month >> date.day >> date.year;
 * 
 * STEP 2 - In demonstrateStructPassing():
 *    1. Declare: Date today;
 *    2. Call: getDate(today);
 *    3. Display: "You entered: " followed by today.month, today.day, today.year
 * 
 * REMEMBER:
 * - Pass by reference using & in parameter
 * - Function can modify the original struct
 * - More efficient than passing by value (no copying)
 */
void getDate(Date &date) {
    // TODO: Implement this function
    // Prompt for and read date into the reference parameter
    
}

void demonstrateStructPassing() {
    cout << "\n=== SECTION 8: Passing Structs to Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 9: STRUCT CONSTRUCTORS
// ============================================================================
/*
 * TASK: Add a constructor to a struct
 * 
 * STEPS:
 * 1. Define a struct with constructor (modify Box struct or create new one):
 *    struct Box {
 *        int width;
 *        int height;
 *        int length;
 *        
 *        // Constructor - same name as struct
 *        Box() {
 *            width = 0;
 *            height = 0;
 *            length = 0;
 *        }
 *    };
 * 
 * 2. Create a Box object:
 *    - Box emptyBox;  // Constructor automatically called
 * 
 * 3. Display the values:
 *    - Output: "Empty box dimensions: " followed by all zeros
 * 
 * 4. Assign new values:
 *    - emptyBox.width = 5;
 *    - emptyBox.height = 5;
 *    - emptyBox.length = 5;
 * 
 * 5. Display again:
 *    - Output: "After assignment: " followed by new dimensions
 * 
 * REMEMBER:
 * - Constructor has same name as struct
 * - Constructor is called automatically when object is created
 * - Use constructor to initialize data members
 */
void demonstrateStructConstructors() {
    cout << "\n=== SECTION 9: Struct Constructors ===\n\n";
    
    // TODO: Write your code here following the instructions above
    // Note: You may need to define a struct with constructor here or modify Box
    
}

// ============================================================================
// SECTION 10: ARRAY OF STRUCT OBJECTS
// ============================================================================
/*
 * TASK: Create and use an array of struct objects
 * 
 * STEPS:
 * 1. The Record struct is already defined above main()
 * 
 * 2. Declare const int SIZE = 5;
 * 3. Declare array: Record records[SIZE];
 * 
 * 4. Use a loop to input data for each record:
 *    - Loop from i = 0 to i < SIZE
 *    - Prompt: "AGE: "
 *    - Read: cin >> records[i].age;
 *    - Use: cin.ignore(); to clear newline
 *    - Prompt: "NAME: "
 *    - Read: getline(cin, records[i].name);
 * 
 * 5. Use another loop to display all records:
 *    - Loop from i = 0 to i < SIZE
 *    - Output: "Record " followed by i+1, ": " followed by name and age
 * 
 * REMEMBER:
 * - Each array element is a struct object
 * - Use array[index].member to access members
 * - Useful for storing multiple records (like a database)
 */
void demonstrateStructArray() {
    cout << "\n=== SECTION 10: Array of Struct Objects ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

