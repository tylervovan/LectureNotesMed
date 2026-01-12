/*
 * Lecture 9 Learning Template - c_string and <cctype>
 * 
 * INSTRUCTIONS:
 * This is a guided learning file. Follow the comments in each section to
 * write the code yourself. Uncomment sections in main() as you complete them.
 * Compile and run to test your work!
 */

#include <iostream>
#include <cctype>   // For character testing and conversion functions
#include <cstring>  // For c-string functions (strcpy, strcat, strlen, strcmp)
#include <string>   // For std::string data type

using namespace std;

// Function Prototypes - Sectioned and Clear, for Good Coding Practice

// Section 1: <cctype> Functions
void demonstrateCctype();

// Section 2: C-string Basics
void demonstrateCstringBasics();

// Section 3: C-string Functions
void demonstrateCstringFunctions();

// Section 4: Passing C-strings to Functions
void displayName(char name[]);  // Helper function for Section 4
void demonstrateCstringPassing();

// Section 5: std::string Operations
void demonstrateStringOperations();

// Section 6: string vs c-string Comparison
void demonstrateComparison();


// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    cout << "========================================" << endl;
    cout << "  LECTURE 9 LEARNING TEMPLATE" << endl;
    cout << "========================================" << endl;
    
    // TODO: Uncomment sections as you complete them to test your code:
    
    demonstrateCctype();              // Section 1: <cctype> functions
    demonstrateCstringBasics();      // Section 2: C-string basics
    demonstrateCstringFunctions();   // Section 3: C-string functions
    demonstrateCstringPassing();     // Section 4: Passing c-strings to functions
    demonstrateStringOperations();    // Section 5: std::string operations
    demonstrateComparison();         // Section 6: string vs c-string comparison
    
    cout << "\n========================================" << endl;
    cout << "  Remember to uncomment sections in main() to test!" << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}

// ============================================================================
// SECTION 1: <cctype> FUNCTIONS
// ============================================================================
/*
 * TASK: Write code to demonstrate <cctype> functions
 * 
 * STEPS:
 * 1. Declare a char variable called 'character'
 * 2. Prompt the user: "Enter a character: "
 * 3. Read the character using cin
 * 4. Use cin.ignore() to clear the newline from the buffer
 * 
 * 5. Test the character using these functions (use if statements):
 *    - isalpha(character) - check if alphabetic (A-Z, a-z)
 *    - isalnum(character) - check if alphanumeric (A-Z, a-z, 0-9)
 *    - isdigit(character) - check if digit (0-9)
 *    - islower(character) - check if lowercase (a-z)
 *    - isupper(character) - check if uppercase (A-Z)
 * 
 *    For each test, output a message like:
 *    "  - isalpha(): The character is alphabetic (A-Z, a-z)"
 * 
 * 6. Convert the character using:
 *    - toupper(character) - convert to uppercase
 *    - tolower(character) - convert to lowercase
 * 
 *    Output: "  - toupper(): [original] -> [uppercase]"
 *            "  - tolower(): [original] -> [lowercase]"
 * 
 * HINT: toupper() and tolower() return int, cast to char: (char)toupper(character)
 * 
 * REMEMBER: These functions return non-zero (true) or 0 (false)
 */
void demonstrateCctype() {
    cout << "\n=== SECTION 1: <cctype> Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    char character{};

    cout << "Enter a character: ";
    cin >> character;
    cin.ignore();

    //testing the character
    if (isalpha(character)){
        cout << "The character is alphabetic (A-Z, a-z)" << endl;
    } else {
        cout << "The character is not alphabetic (A-Z, a-z)" << endl;
    }

    if (isalnum(character)){
        cout << "The character is alphanumeric (A-Z, a-z, 0-9)" << endl;
    } else {
        cout << "The character is not alphanumeric (A-Z, a-z, 0-9)" << endl;
    }

    if (isdigit(character)){
        cout << "The character is a digit (0-9)" << endl;
    } else {
        cout << "The character is not a digit (0-9)" << endl;
    }

    if (islower(character)){
        cout << "The character is lowercase (a-z)" << endl;
    } else {
        cout << "The character is not lowercase (a-z)" << endl;
    }
    
    if (isupper(character)){
        cout << "The character is uppercase (A-Z)" << endl;
    } else {
        cout << "The character is not uppercase (A-Z)" << endl;
    }

    //converting the character
    char uppercase_character = toupper(character);
    char lowercase_character = tolower(character);

    cout << "The uppercase character is: " << uppercase_character << endl;
}

// ============================================================================
// SECTION 2: C-STRING BASICS
// ============================================================================
/*
 * TASK: Learn how to declare, initialize, and read c-strings
 * 
 * STEPS:
 * 1. Declare a constant SIZE = 30
 * 
 * 2. Method 1 - Initialize with string literal:
 *    - Declare: char name1[SIZE] = "Bob";
 *    - Output: "1. Initialized: " followed by name1
 * 
 * 3. Method 2 - Initialize empty string:
 *    - Declare: char name2[SIZE] = {'\0'};  (or {NULL} or {0})
 *    - Output: "2. Empty string initialized"
 * 
 * 4. Method 3 - Read from keyboard:
 *    - Declare: char name3[SIZE];
 *    - Prompt: "3. Enter your name: "
 *    - Read using: cin.getline(name3, SIZE);
 *      (This reads up to SIZE-1 characters and adds '\0' automatically)
 *    - Output: "   You entered: " followed by name3
 * 
 * 5. Display the c-string:
 *    - Output: "4. Displaying c-string: " followed by name3
 * 
 * REMEMBER: 
 * - c-strings are null-terminated character arrays
 * - cin.getline() automatically adds the null character '\0'
 * - You can output c-strings directly with cout
 */
void demonstrateCstringBasics() {
    cout << "\n=== SECTION 2: C-string Basics ===\n\n";
    constant SIZE = 30; 

    char name1[SIZE] = "Bob";
    cout << "1. Initialized: " << name1 << endl;

    char name2[SIZE] = {NULL};

    cout << "2. Empty string initialized" << endl;

    char name3[SIZE];
    cout << "3. Enter your name: ";
    cin.getline(name3, SIZE);
    cout << "   You entered: " << name3 << endl;

    cout << "4. Displaying c-string: " << name3 << endl;


    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 3: C-STRING FUNCTIONS
// ============================================================================
/*
 * TASK: Practice using c-string functions from <cstring>
 * 
 * STEPS:
 * 1. Declare const int SIZE = 50
 * 2. Declare these c-strings:
 *    - char str1[SIZE];
 *    - char str2[SIZE] = "Hello";
 *    - char str3[SIZE] = "World";
 * 
 * 3. Use strcpy_s() to copy:
 *    - Copy "Hello" into str1: strcpy_s(str1, "Hello");
 *    - Output: "1. strcpy_s(str1, \"Hello\"): " followed by str1
 * 
 * 4. Use strcat_s() to concatenate:
 *    - Concatenate " " to str1: strcat_s(str1, " ");
 *    - Concatenate str3 to str1: strcat_s(str1, str3);
 *    - Output: "2. After strcat_s(): " followed by str1
 * 
 * 5. Use strlen() to get length:
 *    - Output: "3. strlen(\"Hello\"): " followed by strlen("Hello")
 *    - Output: "   strlen(str1): " followed by strlen(str1)
 * 
 * 6. Use strcmp() to compare (case-sensitive):
 *    - Declare: char str4[SIZE] = "Hello";
 *    - Declare: char str5[SIZE] = "hello";
 *    - Compare str2 and str4: int result = strcmp(str2, str4);
 *      Output: "4. strcmp(\"Hello\", \"Hello\"): " followed by result and " (0 = equal)"
 *    - Compare str2 and str5: result = strcmp(str2, str5);
 *      Output: "   strcmp(\"Hello\", \"hello\"): " followed by result and " (non-zero = not equal)"
 * 
 * 7. Use _strcmpi() for case-insensitive comparison:
 *    - Compare str2 and str5: result = _strcmpi(str2, str5);
 *      Output: "5. _strcmpi(\"Hello\", \"hello\"): " followed by result and " (0 = equal, case-insensitive)"
 * 
 * 8. Example: Combine two halves of alphabet:
 *    - Declare: char firstHalf[14] = "abcdefghijklm";
 *    - Declare: char secondHalf[14] = "nopqrstuvwxyz";
 *    - Declare: char alphabet[27];
 *    - Copy firstHalf to alphabet: strcpy_s(alphabet, firstHalf);
 *    - Concatenate secondHalf: strcat_s(alphabet, secondHalf);
 *    - Output: "\n6. Combined alphabet: " followed by alphabet
 *    - Output: "   Length of firstHalf: " followed by strlen(firstHalf)
 *    - Output: "   Length of alphabet: " followed by strlen(alphabet)
 * 
 * REMEMBER:
 * - strcpy_s(destination, source) - copies source to destination
 * - strcat_s(destination, source) - appends source to destination
 * - strlen(string) - returns length excluding null character
 * - strcmp(str1, str2) - returns 0 if equal (case-sensitive)
 * - _strcmpi(str1, str2) - returns 0 if equal (case-insensitive)
 */
void demonstrateCstringFunctions() {
    cout << "\n=== SECTION 3: C-string Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 4: PASSING C-STRING TO FUNCTIONS
// ============================================================================
/*
 * TASK: Write a helper function and call it with a c-string
 * 
 * STEP 1 - Write the helper function displayName():
 *    - Parameter: char name[]
 *    - Output: "Your name is: " followed by name
 *    - (This function is declared above, implement it here)
 * 
 * STEP 2 - In demonstrateCstringPassing():
 *    1. Declare const int SIZE = 30
 *    2. Declare: char name[SIZE];
 *    3. Prompt: "Enter your name: "
 *    4. Read: cin.getline(name, SIZE);
 *    5. Call: displayName(name);
 * 
 * REMEMBER:
 * - When you pass an array to a function, you're passing the address of the first element
 * - The function can modify the original array
 * - You can use name[] or name in the function parameter
 */
void displayName(char name[]) {
    // TODO: Implement this function
    // Output: "Your name is: " followed by the name parameter
    
}

void demonstrateCstringPassing() {
    cout << "\n=== SECTION 4: Passing C-string to Functions ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 5: std::string OPERATIONS
// ============================================================================
/*
 * TASK: Practice std::string operations and member functions
 * 
 * STEPS:
 * 1. Declare and initialize:
 *    - string str1;
 *    - string str2 = "Day";
 *    - string message;
 * 
 * 2. Assignment (works with string, NOT with c-string):
 *    - Assign: str1 = "Sunny";
 *    - Output: "1. Assignment: str1 = \"Sunny\" -> " followed by str1
 * 
 * 3. Concatenation using + operator:
 *    - Concatenate: message = str1 + " " + str2;
 *    - Output: "2. Concatenation: str1 + \" \" + str2 -> " followed by message
 *    - Note: + works only if at least one operand is a string variable
 * 
 * 4. More concatenation:
 *    - Concatenate: str1 = str1 + "Day";
 *    - Output: "3. str1 = str1 + \"Day\" -> " followed by str1
 *    - Note: This works! But "Sunny" + " " + "Day" would NOT work
 * 
 * 5. length() function:
 *    - Declare: string firstName = "Tom";
 *    - Declare: string fullName = firstName + " " + "Smith";
 *    - Output: "\n4. Length function:"
 *    - Output: "   firstName.length(): " followed by firstName.length() and " characters"
 *    - Output: "   fullName.length(): " followed by fullName.length() and " characters"
 * 
 * 6. substr() function:
 *    - Declare: string msg = "To be or not to be, this is the question.";
 *    - Output: "\n5. Substring function:"
 *    - Output: "   Original: " followed by msg
 *    - Output: "   msg.substr(3, 15): " followed by msg.substr(3, 15)
 *    - Output: "   msg.substr(0, 5): " followed by msg.substr(0, 5)
 *    - Note: substr(start_index, number_of_characters)
 * 
 * 7. find() function:
 *    - Output: "\n6. Find function:"
 *    - Output: "   msg.find(\"not to be\"): " followed by msg.find("not to be")
 *    - Output: "   msg.find(\"be\"): " followed by msg.find("be")
 *    - Note: find() returns the index where substring begins
 * 
 * 8. Reading string from keyboard:
 *    - Declare: string userInput;
 *    - Prompt: "\n7. Enter a message: "
 *    - Read: getline(cin, userInput);  // Note: getline() for string, cin.getline() for c-string
 *    - Output: "   You entered: " followed by userInput
 * 
 * REMEMBER:
 * - string uses getline(cin, variable)
 * - c-string uses cin.getline(array, SIZE)
 * - Assignment operator (=) works with string
 * - + operator works if at least one operand is a string variable
 */
void demonstrateStringOperations() {
    cout << "\n=== SECTION 5: std::string Operations ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}

// ============================================================================
// SECTION 6: COMPARISON - string vs c-string
// ============================================================================
/*
 * TASK: Compare how string and c-string handle the same operations
 * 
 * STEPS:
 * 1. Declare const int SIZE = 30
 * 
 * 2. STRING operations:
 *    - Declare: string strName = "Tom Lee";
 *    - Output: "STRING:"
 *    - Output: "  Declaration: string strName;"
 *    - Output: "  Initialize: string strName = \"Tom Lee\";"
 *    - Output: "  Assignment: strName = \"Bob Jones\";"
 *    - Assign: strName = "Bob Jones";
 *    - Output: "    Result: " followed by strName
 *    - Output: "  Concatenate: strName = \"Bob\" + \" \" + \"Jones\";"
 *    - Concatenate: strName = "Bob" + string(" ") + "Jones";
 *      (Note: Need to convert one literal to string for + to work)
 *    - Output: "    Result: " followed by strName
 *    - Output: "  Read input: getline(cin, strName);"
 * 
 * 3. C-STRING operations:
 *    - Declare: char cstrName[SIZE] = "Tom Lee";
 *    - Output: "\nC-STRING:"
 *    - Output: "  Declaration: char cstrName[30];"
 *    - Output: "  Initialize: char cstrName[30] = \"Tom Lee\";"
 *    - Output: "  Assignment: strcpy_s(cstrName, \"Bob Jones\");"
 *    - Assign: strcpy_s(cstrName, "Bob Jones");
 *    - Output: "    Result: " followed by cstrName
 *    - Output: "  Concatenate: strcpy(cstrName, \"Bob\"); strcat(cstrName, \" \"); strcat(cstrName, \"Jones\");"
 *    - Concatenate:
 *        strcpy_s(cstrName, "Bob");
 *        strcat_s(cstrName, " ");
 *        strcat_s(cstrName, "Jones");
 *    - Output: "    Result: " followed by cstrName
 *    - Output: "  Read input: cin.getline(cstrName, SIZE);"
 * 
 * REMEMBER:
 * - string: Use = for assignment, + for concatenation, getline() for input
 * - c-string: Use strcpy_s() for assignment, strcat_s() for concatenation, cin.getline() for input
 * - string is easier to use but c-string gives you more control
 */
void demonstrateComparison() {
    cout << "\n=== SECTION 6: string vs c-string Comparison ===\n\n";
    
    // TODO: Write your code here following the instructions above
    
}
