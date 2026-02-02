# Lecture #9: c_string and <cctype>

## String vs c_string & <cctype> Functions

The `<cctype>` library provides seven standard C++ functions for character testing and conversion.
**Return Type**: All these functions return an `int`. If the condition is true, a non-zero value is returned; otherwise, 0 is returned.

### Character Testing Functions
| Function | Description |
| :--- | :--- |
| `isalpha(c)` | Returns non-zero if `c` is alphabetic ('A'-'Z', 'a'-'z'). |
| `isalnum(c)` | Returns non-zero if `c` is alphanumeric ('A'-'Z', 'a'-'z', '0'-'9'). |
| `isdigit(c)` | Returns non-zero if `c` is a digit ('0'-'9'). |
| `islower(c)` | Returns non-zero if `c` is lowercase ('a'-'z'). |
| `isupper(c)` | Returns non-zero if `c` is uppercase ('A'-'Z'). |

### Character Conversion Functions
| Function | Description |
| :--- | :--- |
| `toupper(c)` | Converts lowercase `c` to uppercase. |
| `tolower(c)` | Converts uppercase `c` to lowercase. |

### Example
```cpp
#include <iostream>
#include <cctype> 
using namespace std;

int main() {
    char character;
    cout << "Enter a character: ";
    cin >> character;

    if (isalpha(character))
        cout << "The character is an alphabetic character.\n";
    else
        cout << "The character is not an alphabetic character.\n";
        
    return 0;
}
```

## Character Array (c-string)
- A sequence of characters stored in an array.
- A **c-string** is a null-terminated character array.
- The computer places a null character (`\0`) at the end of the string.

### Reading c-strings
Use `cin.getline()` to read a line of text into a character array.

```cpp
#include <iostream>
using namespace std;

const int SIZE = 30;

void displayName(char name[]);

int main() {
    char name[SIZE];
    cout << "Enter your name: ";
    // Reads up to 29 characters, 30th is '\0'
    cin.getline(name, SIZE); 
    
    displayName(name);
    return 0;
}

void displayName(char name[]) {
    cout << "Your name is: " << name << endl;
}
```

## std::string vs. c-string

| Feature | `std::string` | `c-string` (char array) |
| :--- | :--- | :--- |
| **Header** | `#include <string>` | No header for basic usage (`<cstring>` for functions) |
| **Declaration** | `string name;` | `char name[SIZE];` |
| **Input** | `getline(cin, name);` | `cin.getline(name, SIZE);` |
| **Terminator** | Managed internally | Null character (`\0`, ASCII 0) required |

### Null Character
The null character marks the end of a c-string. It can be represented as:
- `NULL` (predefined constant)
- `'\0'` (ASCII character)
- `0` (ASCII integer value)

### Initialization
```cpp
// 1. Initialize with string literal (automatically adds null)
char fullName[30] = "Bob"; 

// 2. Empty string
char empty[30] = {'\0'};
```
*Note*: `fullName = "Tom";` is **invalid** for arrays after declaration.

### Assigning Values to c-strings
1.  **Initialization**: `char name[20] = "Bob";`
2.  **Copy**: `strcpy_s(name, "Tom");` (requires `<cstring>`)
3.  **Input**: `cin.getline(name, 30);`

## c-string Functions
Requires `#include <cstring>` (or `<string.h>` in C).

### 1. `strcpy_s(dest, src)` - Copy String
Copies the contents of `src` into `dest`, overwriting whatever was in `dest`.

```cpp
char source[20] = "Hello";
char destination[20];

strcpy_s(destination, source);

cout << destination; // Output: Hello
```

### 2. `strcat_s(dest, src)` - Concatenate String
Appends `src` to the end of `dest`. The destination must have enough space.

```cpp
char greeting[30] = "Hello";
char name[10] = " World";

strcat_s(greeting, name);

cout << greeting; // Output: Hello World
```

### 3. `strlen(str)` - String Length
Returns the number of characters in the string (excluding the null terminator).

```cpp
char word[20] = "Programming";

cout << strlen(word); // Output: 11

char empty[20] = "";
cout << strlen(empty); // Output: 0
```

### 4. `strcmp(str1, str2)` - Compare Strings (Case-Sensitive)
Compares two strings character by character. Returns:
- `0` if strings are equal
- Negative value if `str1` < `str2`
- Positive value if `str1` > `str2`

```cpp
char word1[10] = "apple";
char word2[10] = "apple";
char word3[10] = "Apple";

cout << strcmp(word1, word2); // Output: 0 (equal)
cout << strcmp(word1, word3); // Output: positive ('a' > 'A' in ASCII)

if (strcmp(word1, word2) == 0) {
    cout << "The strings are equal";
}
```

### 5. `_strcmpi(str1, str2)` - Compare Strings (Case-Insensitive)
Same as `strcmp`, but ignores uppercase/lowercase differences.

```cpp
char word1[10] = "Hello";
char word2[10] = "HELLO";
char word3[10] = "hello";

cout << _strcmpi(word1, word2); // Output: 0 (equal, ignoring case)
cout << _strcmpi(word1, word3); // Output: 0 (equal, ignoring case)

if (_strcmpi(word1, word2) == 0) {
    cout << "The strings are equal (case-insensitive)";
}
```

### Combined Example
```cpp
char firstHalf[14] = "abcdefghijklm";
char secondHalf[14] = "nopqrstuvwxyz";
char alphabet[27];

strcpy_s(alphabet, firstHalf);    // alphabet = "abcdefghijklm"
strcat_s(alphabet, secondHalf);   // alphabet = "abcdefghijklmnopqrstuvwxyz"

cout << alphabet;                 // abcdefghijklmnopqrstuvwxyz
cout << strlen(firstHalf);        // 13
cout << strlen(alphabet);         // 26
```

## std::string Operations
The `string` class (requires `#include <string>`) offers easier manipulation.

### Operators
-   **Assignment**: `str1 = "Sunny";`
-   **Concatenation**: `message = str1 + " " + str2;`
    -   *Note*: At least one operand must be a string variable (e.g., `"A" + "B"` is invalid).

### Member Functions
1.  **`length()`**: Returns number of characters.
    ```cpp
    string name = "Tom";
    cout << name.length(); // 3
    ```
2.  **`substr(index, length)`**: Returns a substring.
    ```cpp
    string msg = "To be or not to be";
    cout << msg.substr(3, 2); // "be"
    ```
3.  **`find(substring)`**: Returns the starting index of substring or `string::npos` if not found.
    ```cpp
    cout << msg.find("not"); // Returns index
    ```

## Summary Comparison

| Operation | `std::string` | `c-string` |
| :--- | :--- | :--- |
| **Initialize** | `string name = "Tom";` | `char name[30] = "Tom";` |
| **Assignment** | `name = "Bob";` | `strcpy_s(name, "Bob");` |
| **Concatenate** | `name = "Bob" + " " + "Jones";` | `strcpy(name, "Bob"); strcat(name, " "); ...` |
| **Read Line** | `getline(cin, name);` | `cin.getline(name, SIZE);` |

