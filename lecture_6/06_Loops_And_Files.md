# Lecture 6: Loops and File I/O

## C Standard Headers
- `<iostream>`: Standard Input/Output.
- `<fstream>`: File Input/Output (`ifstream`, `ofstream`).
- `<string>`: String variables.
- `<cmath>`: Math functions (`sqrt`, `pow`, etc).
- `<iomanip>`: Formatted output (`setw`, `setprecision`).

## Loop Control Structures

### While Loop
Repeats code while condition is true.
- Check condition -> Execute body -> Repeat.
- **Infinite Loop**: Occurs if condition never becomes false (Ctrl+C to stop).

```cpp
int count = 0;
while (count < 10) {
    // ...
    count++;
}
```

### Loop Types
- **Count-Controlled**: Fixed number of iterations.
- **Event-Controlled**: Continues until specific event (e.g., end-of-file).
- **Sentinel-Controlled**: Uses a specific value (e.g., -1) to stop.
- **Flag-Controlled**: Uses boolean variable.

### Do-While Loop
Post-test loop. Body always executes **at least once**.
```cpp
do {
    // ...
} while (condition); // Note the semicolon!
```

### For Loop
Compact notation for count-controlled loops.
```cpp
// for (initialization; condition; increment)
for (int i = 0; i < 5; i++) {
    // ...
}
```

## Random Number Generation
Requires `<cstdlib>` (implied) and `<ctime>`.
1. **Seed**: `srand(time(NULL));` (Call once).
2. **Generate**: `rand()`.
   - Range: `rand() % 6 + 1` (1 to 6).

## File Input and Output
### Steps
1. Include library: `#include <fstream>`
2. Declare stream variables:
   ```cpp
   ifstream inFile;
   ofstream outFile;
   ```
3. Open file:
   ```cpp
   inFile.open("input.txt");
   outFile.open("output.txt");
   ```
4. Check for success:
   ```cpp
   if (!inFile) { /* error handling */ }
   // or
   if (inFile.fail()) { /* error handling */ }
   ```
5. Use stream (like `cin`/`cout`):
   ```cpp
   inFile >> number;
   outFile << "Result: " << number;
   ```
   - Reading line-by-line:
     ```cpp
     while (getline(inFile, line)) { ... }
     ```
6. Close file:
   ```cpp
   inFile.close();
   outFile.close();
   ```
