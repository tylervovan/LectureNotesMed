# Lecture 4: Standard Input Stream & Buffer

## `cin` and Input Streams
- **`cin`**: Input object representing the keyboard.
- **Input Stream**: Continuous sequence of characters.
- **Input Buffer**: Temporary storage for characters before processing.

## The Extraction Operator (`>>`)
- Used with `cin` to extract data.
- **Skips leading whitespace** (spaces, tabs, newlines).
- Stops reading at the next whitespace.

```cpp
int value1, value2;
cout << "Enter two values: ";
cin >> value1 >> value2;
```

## Reading Strings with Whitespace
### The Problem
`cin >>` stops at whitespace, so it cannot read strings with spaces (e.g., "Tom Lee").

### Solution: `getline()`
- Reads entire line until newline (`\n`).
- Consumes the newline character.
- Requires `<string>`.

```cpp
string fullName;
getline(cin, fullName);
```

### Mixing `cin >>` and `getline()`
**Issue**: `cin >>` leaves the newline (`\n`) in the buffer. A subsequent `getline()` sees this newline immediately and reads an empty string.

**Solution**: Use `cin.ignore()` to clear the buffer.

```cpp
int age;
string fullName;

cout << "Enter your age: ";
cin >> age;

cin.ignore(); // Consumes the leftover '\n'

cout << "Enter your full name: ";
getline(cin, fullName);
```

## `cin.get()`
- Reads a **single character**, including whitespace/newline.
- Can only read into a `char` variable.

## Summary of Input Methods

| Method | Advantages | Disadvantages |
| :--- | :--- | :--- |
| `cin >>` | Reads all standard types. | Stops at whitespace (no spaces in strings). |
| `getline()` | Reads entire string with spaces. | Only for strings. Stops at `\n`. |
| `cin.get()` | Reads any single char (inc. whitespace). | Only for single `char`. |
