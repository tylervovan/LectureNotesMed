# Lecture 6 - Advanced File Operations

## Review: Text Files (5 Steps)

```cpp
#include <iostream>
#include <fstream>          // Step 1: Include file stream library

int main()
{
    ifstream infile;        // Step 2: Create file object (ifstream to read)
    ofstream outfile;       //         (ofstream to write)

    infile.open("c:\\data.txt");    // Step 3: Open the file
    outfile.open("c:\\names.txt");

    infile >> number;       // Step 4: Read or write to file
    outfile << name;

    infile.close();         // Step 5: Close the file
    outfile.close();

    return 0;
}
```

**Note:** Although files are closed when a program ends, it's good practice to close files when no longer needed.

---

## Checking for File Open Errors (Fail State)

C++ does NOT automatically generate an error if a file fails to open. You must check manually.

### Method 1: Using `fail()` function

```cpp
if (outFile.fail())         // Returns true if file failed to open
{
    cout << "File did not open\n";
    return 1;               // Return 1 to OS, program closes
}
```

### Method 2: Using the file object directly

```cpp
if (!inFile)                // If file does not open
{
    cout << "Error opening file.";
    exit(1);                // Defined in <cstdlib>, closes program
}
```

---

## End-of-File (EOF)

When a file is written, the OS automatically writes an EOF marker at the end.

### Using `.eof()` function

```cpp
while (!inFile.eof())       // While NOT end of file
{
    inFile >> number;
    cout << number << endl;
}
```

### Alternative: Using extraction in condition

```cpp
while (inFile >> number)    // Returns false at EOF
{
    cout << number << endl;
}
```

---

## Runtime Input of File Names

```cpp
ifstream inFile;
char fileName[30];

cout << "Enter the input file name: ";
cin >> fileName;            // Or: cin.getline(fileName, 30)

inFile.open(fileName);
```

---

## Using fstream Data Type

`fstream` can be used for both input AND output, but the mode must be specified.

```cpp
#include <fstream>

int main()
{
    fstream dataFile;

    // open() takes 2 arguments: filename and file access flag
    dataFile.open("info.txt", ios::out);
}
```

---

## File Access Flags

| Flag | Description |
|------|-------------|
| `ios::in` | Input mode (reading) |
| `ios::out` | Output mode (writing) - overwrites existing data by default |
| `ios::trunc` | Truncate - delete existing contents (default with `ios::out`) |
| `ios::app` | Append mode - preserve contents, write to end |
| `ios::binary` | Binary mode - read/write in binary form (text is default) |

### Combining Flags with `|` Operator

```cpp
dataFile.open("info.txt", ios::out | ios::app);  // Output + Append
```

### Opening File at Declaration

```cpp
fstream dataFile("names.txt", ios::out | ios::app);

if (!dataFile)
    cout << "Error opening file";
```

**Note:** A file can be opened in BOTH input and output mode only for **binary files** (not text).

---

## File Output Formatting

File output can be formatted the same way as screen output:

```cpp
#include <fstream>
#include <iomanip>

int main()
{
    fstream dataFile("numbers.txt", ios::out);
    double number = 17.123456;

    dataFile << fixed << showpoint << setprecision(3)
             << number << endl;     // Output: 17.123

    dataFile << setprecision(1)
             << number << endl;     // Output: 17.1

    dataFile.close();
    return 0;
}
```

---

## Passing File Stream Objects to Functions

File stream objects must **always be passed by reference**.

```cpp
bool readFile(fstream &file, char *name);
void showContents(fstream &file);

int main()
{
    fstream inFile;

    if (!readFile(inFile, "data.txt"))
    {
        cout << "Error opening file!\n";
        return 0;
    }

    showContents(inFile);
    inFile.close();
    return 0;
}

bool readFile(fstream &file, char *name)
{
    file.open(name, ios::in);
    return !file.fail();
}

void showContents(fstream &file)
{
    char line[81];
    while (file >> line)
    {
        cout << line << endl;
    }
}
```

---

## Extraction Operator (`>>`) vs `getline()`

### Problem with Extraction Operator

The `>>` operator stops reading at **any whitespace** (`\n`, `\t`, ` `).

```cpp
// File contains: "Tom Lee"
string name;
inFile >> name;     // name = "Tom" (stops at space!)
```

### Solution: Use `getline()`

```cpp
// For string:
getline(inFile, name, '\n');        // Reads until newline

// For c_string:
inFile.getline(name, 30, '\n');     // Reads up to 29 chars or newline
```

The 3rd parameter (delimiter) defaults to `'\n'` but can be changed.

---

## Delimiters

A **delimiter** is a character used to separate fields in a file.

### Examples
- Comma delimited: `20,Jimmy Page,400 Oak Street,23,Tom Lee`
- Slash delimited: `18/Bill Bell/123 Main Street/33/Pete Townsend`

### Reading Delimited Files

```cpp
// String with slash delimiter:
string name;
while (!file.eof())
{
    getline(file, name, '/');   // Reads until '/', absorbs delimiter
    cout << name << endl;
}

// C-string with comma delimiter:
char name[30];
while (!file.eof())
{
    file.getline(name, 30, ',');
    cout << name << endl;
}
```

---

## Character-Level File Functions

### `get()` - Read One Character

Reads the next character, including whitespace.

```cpp
char character;
inFile.get(character);

while (!inFile.eof())
{
    cout << character;
    inFile.get(character);
}
```

### `putback()` - Move Pointer Back

Moves the get pointer back one character.

```cpp
inFile.get(character);
while (!inFile.eof())
{
    if (character == '<')
    {
        inFile.putback(character);  // Put it back, then do something
    }
    else
        inFile.get(character);
}
```

### `peek()` - Look Ahead

Looks at the next character without reading it.

```cpp
inFile.get(character);
while (!inFile.eof())
{
    if (inFile.peek() == '>')
        // do something
    else
        inFile.get(character);
}
```

---

## Text Files vs Binary Files

### Text Files (Default)

- Contains ASCII characters
- Data stored character by character
- Line length is NOT fixed
- Uses `>>` and `<<` operators
- Searching is linear (slower)

### Binary Files

- Contains strings of bits, uninterpreted
- Data stored based on data type (fixed lengths)
- Must specify `ios::binary` flag
- Uses `read()` and `write()` functions
- Records can be accessed and modified directly (random access)

```cpp
file.open("data.bin", ios::binary | ios::out);
```

---

## sizeof() Function

Returns the number of bytes a data type requires.

```cpp
cout << sizeof(int);      // 4 bytes
cout << sizeof(float);    // 4 bytes
cout << sizeof(double);   // 8 bytes
cout << sizeof(char);     // 1 byte
```

Works with structs and classes too:

```cpp
cout << sizeof(Student);  // Total bytes of all members
```

---

## write() Function (Binary Output)

Writes data to a binary file.

**Syntax:** `fileObject.write(address, size);`

The first parameter must be a `char*` pointer.

### Writing char arrays (works directly)

```cpp
char name[20] = "Tom Lee";
outFile.write(name, sizeof(name));
```

### Writing non-char types (requires typecast)

```cpp
int ages[5] = {21, 27, 13, 42, 15};

file.write(reinterpret_cast<char*>(ages), sizeof(ages));

// Alternative syntax:
file.write((char*)ages, sizeof(ages));
```

### Writing struct/class objects

```cpp
Person person;
file.write(reinterpret_cast<char*>(&person), sizeof(person));

// Or:
file.write((char*)&person, sizeof(person));
```

---

## read() Function (Binary Input)

Reads data from a binary file.

**Syntax:** `fileObject.read(address, size);`

```cpp
// Reading char array:
char name[20];
file.read(name, sizeof(name));

// Reading non-char types:
int ages[5];
file.read(reinterpret_cast<char*>(ages), sizeof(ages));

// Reading struct:
Person person;
file.read(reinterpret_cast<char*>(&person), sizeof(person));
```

---

## Sequential vs Random File Access

### Sequential Access

- Reads/writes from beginning to end
- Must read all preceding records to reach a specific record
- **Inefficient** for large files

### Random Access

- Can jump to any byte in the file
- Uses `seekp()` and `seekg()` functions

---

## Seeking Functions

C++ maintains two pointers:
- **get pointer** - where to read next byte
- **put pointer** - where to write next byte

### seekp() - Seek Put (for output)

Moves the put pointer before writing.

**Syntax:** `file.seekp(byteOffset, origin);`

```cpp
file.seekp(0L, ios::beg);    // Move to beginning
file.seekp(0L, ios::end);    // Move to end
file.seekp(20L, ios::cur);   // Move 20 bytes from current position
```

### seekg() - Seek Get (for input)

Moves the get pointer before reading.

**Syntax:** `file.seekg(byteOffset, origin);`

```cpp
file.seekg(10L, ios::beg);   // Move 10 bytes from beginning
file.seekg(-10L, ios::end);  // Move 10 bytes before end
```

### Origin Flags

| Flag | Position |
|------|----------|
| `ios::beg` | Beginning of file |
| `ios::end` | End of file |
| `ios::cur` | Current position |

---

## Binary Files Summary

```cpp
// Declare and open
fstream file("students.bin", ios::out | ios::in | ios::binary);

// Write to file
file.write(reinterpret_cast<char*>(&student), sizeof(Student));

// Move get pointer to beginning
file.seekg(0L, ios::beg);

// Read first record
file.read(reinterpret_cast<char*>(&student), sizeof(Student));

// Move put pointer to overwrite first record
file.seekp(0L, ios::beg);

// Write record
file.write(reinterpret_cast<char*>(&student), sizeof(Student));

// Append to end
file.seekp(0L, ios::end);
file.write(reinterpret_cast<char*>(&student), sizeof(Student));
```

---

## Variable-Length vs Fixed-Length Files

### Variable-Length Files

- Records can be different sizes
- Uses `string` class (size varies with content)

```cpp
struct student
{
    int id;
    string name;      // Variable size!
    string address;
};
```

### Fixed-Length Files

- All records are the same size
- Uses c_strings (fixed array size)

```cpp
struct student
{
    int id;              // 4 bytes
    char name[50];       // 50 bytes (always)
    char address[100];   // 100 bytes (always)
    float gpa;           // 4 bytes
};                       // Total: 158 bytes per record
```

**Note:** With c_strings, the array uses its full size regardless of content. "Bob" in a `char[50]` still uses 50 bytes.
