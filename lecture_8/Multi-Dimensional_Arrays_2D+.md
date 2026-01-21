# Lecture #8: Multi-Dimensional Arrays (2D+)

## What is a 2D Array?

A **two-dimensional array** is an array of arrays - essentially a table or grid with rows and columns. Think of it like a spreadsheet or a chessboard.

```
        Column 0    Column 1    Column 2
Row 0   [  5  ]     [  10 ]     [  15 ]
Row 1   [  20 ]     [  25 ]     [  30 ]
Row 2   [  35 ]     [  40 ]     [  45 ]
```

## Declaration Syntax

```cpp
dataType arrayName[ROWS][COLS];
```

### Examples
```cpp
const int ROWS = 3;
const int COLS = 4;

int matrix[ROWS][COLS];          // 3 rows, 4 columns of integers
double grades[5][10];            // 5 rows, 10 columns of doubles
char ticTacToe[3][3];            // 3x3 grid for tic-tac-toe
```

## Initialization

### Method 1: Initialize All at Once
```cpp
int matrix[3][4] = {
    {1, 2, 3, 4},      // Row 0
    {5, 6, 7, 8},      // Row 1
    {9, 10, 11, 12}    // Row 2
};
```

### Method 2: Initialize to Zero
```cpp
int matrix[3][4] = {0};  // All elements set to 0
```

### Method 3: Partial Initialization
```cpp
int matrix[3][4] = {
    {1, 2},           // Row 0: {1, 2, 0, 0}
    {5}               // Row 1: {5, 0, 0, 0}
                      // Row 2: {0, 0, 0, 0}
};
```

## Accessing Elements

Use two indices: `arrayName[row][col]`

```cpp
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

cout << matrix[0][0];  // Output: 1 (first element)
cout << matrix[1][2];  // Output: 7 (row 1, column 2)
cout << matrix[2][3];  // Output: 12 (last element)

matrix[1][1] = 100;    // Change element at row 1, col 1
```

## Memory Layout

In C++, 2D arrays are stored in **row-major order** - all elements of row 0 first, then row 1, etc.

```
Memory: [1][2][3][4][5][6][7][8][9][10][11][12]
         └─ Row 0 ─┘└─ Row 1 ─┘└─── Row 2 ───┘
```

## Looping Through 2D Arrays

### Nested For Loops (Most Common)
```cpp
const int ROWS = 3;
const int COLS = 4;
int matrix[ROWS][COLS];

// Outer loop controls rows
// Inner loop controls columns
for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
        cout << matrix[row][col] << " ";
    }
    cout << endl;  // New line after each row
}
```

### Example: Fill Array with User Input
```cpp
const int ROWS = 2;
const int COLS = 3;
int table[ROWS][COLS];

cout << "Enter " << ROWS * COLS << " numbers:\n";
for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
        cout << "Enter value for [" << r << "][" << c << "]: ";
        cin >> table[r][c];
    }
}
```

## Passing 2D Arrays to Functions

**Important**: When passing a 2D array to a function, you must specify the column size.

```cpp
const int COLS = 4;

// Function prototype - column size REQUIRED
void printMatrix(int arr[][COLS], int rows);

// Function definition
void printMatrix(int arr[][COLS], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << arr[r][c] << "\t";
        }
        cout << endl;
    }
}

int main() {
    const int ROWS = 3;
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printMatrix(matrix, ROWS);
    return 0;
}
```

### Why Column Size is Required
The compiler needs the column size to calculate memory addresses. For `arr[r][c]`, it computes:
```
address = base + (r * COLS + c) * sizeof(dataType)
```

## Common Operations

### Sum All Elements
```cpp
int sumAll(int arr[][COLS], int rows) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            total += arr[r][c];
        }
    }
    return total;
}
```

### Sum a Specific Row
```cpp
int sumRow(int arr[][COLS], int rows, int targetRow) {
    int total = 0;
    for (int c = 0; c < COLS; c++) {
        total += arr[targetRow][c];
    }
    return total;
}
```

### Sum a Specific Column
```cpp
int sumColumn(int arr[][COLS], int rows, int targetCol) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        total += arr[r][targetCol];
    }
    return total;
}
```

### Find Maximum Value
```cpp
int findMax(int arr[][COLS], int rows) {
    int max = arr[0][0];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            if (arr[r][c] > max) {
                max = arr[r][c];
            }
        }
    }
    return max;
}
```

## Practical Example: Grade Tracker

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_STUDENTS = 3;
const int NUM_TESTS = 4;

void displayGrades(double grades[][NUM_TESTS], int students);
double calcStudentAvg(double grades[][NUM_TESTS], int student);

int main() {
    double grades[NUM_STUDENTS][NUM_TESTS] = {
        {85.5, 90.0, 78.5, 92.0},   // Student 0
        {76.0, 88.5, 95.0, 82.5},   // Student 1
        {90.0, 91.5, 89.0, 94.5}    // Student 2
    };

    displayGrades(grades, NUM_STUDENTS);

    // Calculate and display each student's average
    for (int s = 0; s < NUM_STUDENTS; s++) {
        cout << "Student " << s << " average: "
             << fixed << setprecision(2)
             << calcStudentAvg(grades, s) << endl;
    }

    return 0;
}

void displayGrades(double grades[][NUM_TESTS], int students) {
    cout << "\t\tTest 1\tTest 2\tTest 3\tTest 4\n";
    cout << "------------------------------------------------\n";

    for (int s = 0; s < students; s++) {
        cout << "Student " << s << ":\t";
        for (int t = 0; t < NUM_TESTS; t++) {
            cout << grades[s][t] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

double calcStudentAvg(double grades[][NUM_TESTS], int student) {
    double sum = 0;
    for (int t = 0; t < NUM_TESTS; t++) {
        sum += grades[student][t];
    }
    return sum / NUM_TESTS;
}
```

## Common Mistakes to Avoid

| Mistake | Problem | Fix |
|:--------|:--------|:----|
| `arr[3,4]` | Comma operator, not 2D access | Use `arr[3][4]` |
| `int arr[][]` in function | Missing column size | Use `int arr[][COLS]` |
| `arr[ROWS][COLS]` | Out of bounds (indices are 0 to size-1) | Use `arr[ROWS-1][COLS-1]` for last element |
| Swapping row/col | Accessing wrong element | Remember: `[row][col]` |

## Summary

| Concept | Syntax |
|:--------|:-------|
| **Declare** | `int arr[ROWS][COLS];` |
| **Initialize** | `int arr[2][3] = {{1,2,3}, {4,5,6}};` |
| **Access** | `arr[row][col]` |
| **Loop** | Nested for loops (outer=rows, inner=cols) |
| **Pass to function** | `void func(int arr[][COLS], int rows)` |

## Higher Dimensional Arrays (3D, 4D, 5D+)

The same concept extends to any number of dimensions. Each dimension adds another index and another nested loop.

### 3D Array - "Cube" or "Stack of Tables"
```cpp
// Think: multiple 2D grids stacked on top of each other
// [depth][row][col] or [layer][row][col]
int cube[2][3][4];  // 2 layers, each with 3 rows and 4 columns
                    // Total elements: 2 * 3 * 4 = 24

// Initialize
int cube[2][3][4] = {
    {   // Layer 0
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    },
    {   // Layer 1
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    }
};

// Access: cube[layer][row][col]
cout << cube[0][1][2];  // Layer 0, row 1, col 2 → 7
cout << cube[1][2][3];  // Layer 1, row 2, col 3 → 24

// Traverse with 3 nested loops
for (int layer = 0; layer < 2; layer++) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << cube[layer][row][col] << " ";
        }
    }
}

// Pass to function - must specify all sizes except first
void process3D(int arr[][3][4], int layers);
```

### 4D Array - "Collection of Cubes"
```cpp
// Think: multiple 3D cubes
// [w][z][y][x] or [time][layer][row][col]
int hyper[2][3][4][5];  // 2 × 3 × 4 × 5 = 120 elements

// Access
hyper[1][2][3][4] = 42;

// Traverse with 4 nested loops
for (int w = 0; w < 2; w++)
    for (int z = 0; z < 3; z++)
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 5; x++)
                cout << hyper[w][z][y][x];

// Pass to function
void process4D(int arr[][3][4][5], int firstDim);
```

### The Pattern for N Dimensions

| Dimensions | Declaration | Loops Needed | Function Parameter |
|:-----------|:------------|:-------------|:-------------------|
| 1D | `arr[A]` | 1 | `arr[]` or `arr[A]` |
| 2D | `arr[A][B]` | 2 | `arr[][B]` |
| 3D | `arr[A][B][C]` | 3 | `arr[][B][C]` |
| 4D | `arr[A][B][C][D]` | 4 | `arr[][B][C][D]` |
| ND | `arr[A][B]...[N]` | N | `arr[][B]...[N]` |

**Rule:** When passing to functions, only the **first** dimension can be omitted. All others must be specified.

### Real-World Uses

| Dimensions | Example Use Case |
|:-----------|:-----------------|
| 3D | Video frames over time `[frame][y][x]`, RGB image `[channel][y][x]`, 3D game world `[z][y][x]` |
| 4D | Video with color `[frame][channel][y][x]`, physics simulations |
| 5D+ | Machine learning tensors, scientific simulations |

### Memory Layout (Still Row-Major)
All dimensions flatten into one continuous block:
```cpp
int arr[2][3][4];  // Stored as: arr[0][0][0], arr[0][0][1], ... arr[1][2][3]
```

The formula extends:
```
address = base + ((i * DIM2 * DIM3) + (j * DIM3) + k) * sizeof(type)
```

## Dimension Omission Rules (Initialization)

When initializing arrays, you can omit the **first dimension only** - the compiler counts initializers to determine it.

### 2D Arrays
```cpp
double score[][2] = {{1,2}, {3,4}, {5,6}};  // ✓ Compiler infers [3][2]
double score[3][] = {{1,2}, {3,4}, {5,6}};  // ✗ ERROR - can't omit second
```

### 3D Arrays - Same Rule
```cpp
int cube[][3][4] = { /* ... */ };   // ✓ Valid - first dim omitted
int cube[2][][4] = { /* ... */ };   // ✗ ERROR - can't omit middle
int cube[2][3][] = { /* ... */ };   // ✗ ERROR - can't omit last
int cube[][][4] = { /* ... */ };    // ✗ ERROR - can't omit multiple
```

### Why Only the First?

The compiler needs all dimensions except the first to calculate memory addresses:

```cpp
// For arr[i][j][k]:
address = base + (i * DIM2 * DIM3 + j * DIM3 + k) * sizeof(type)
//                    ↑      ↑        ↑
//                  need   need     need
```

The first dimension (`DIM1`) doesn't appear in the formula - it only determines total array size, not how to navigate within it.

### Complete Validity Table

| Declaration | Valid? | Reason |
|:------------|:-------|:-------|
| `arr[][4]` | ✓ | First dim omitted, second known |
| `arr[3][]` | ✗ | Must know all dims except first |
| `arr[][3][4]` | ✓ | First dim omitted, others known |
| `arr[2][][4]` | ✗ | Can't omit middle dimension |
| `arr[2][3][]` | ✗ | Can't omit last dimension |
| `arr[][3][]` | ✗ | Can only omit the first |
| `arr[][][4]` | ✗ | Can't omit multiple dimensions |
| `arr[][][]` | ✗ | No dimensions known |

**Rule of thumb:** Only the leftmost `[]` can be empty.

## Key Points to Remember

1. 2D arrays are stored in **row-major order**
2. First index = **row**, second index = **column**
3. Indices start at **0**, not 1
4. Column size must be specified when passing to functions
5. Use **nested loops** to traverse all elements (one loop per dimension)
6. Use **constants** for array dimensions to avoid magic numbers
7. Higher dimensions follow the same pattern - just add more indices and loops
