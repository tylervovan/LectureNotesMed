// =============================================================================
// Program: Lecture 8 - Two-Dimensional Arrays Examples
// =============================================================================
//
// Programmer: CS 1B
// Class: CS 1B
// Instructor: Med Mogasemi
//
// =============================================================================
//
// Description:
// Demonstrates 2D array declaration, initialization, traversal, and
// passing to functions. Includes practical examples for common operations.
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants for array dimensions
const int ROWS = 3;
const int COLS = 4;

// Function prototypes
void printMatrix(int arr[][COLS], int rows);
void fillMatrix(int arr[][COLS], int rows);
int sumAll(int arr[][COLS], int rows);
int sumRow(int arr[][COLS], int rows, int targetRow);
int sumColumn(int arr[][COLS], int rows, int targetCol);
int findMax(int arr[][COLS], int rows);
void demonstrateBasics();
void demonstrateGradeTracker();

// =========== main =====================================================
//
// ======================================================================
int main() {
    int choice;

    do {
        cout << "\n===== 2D Array Demonstrations =====\n";
        cout << "1. Basic 2D Array Operations\n";
        cout << "2. Grade Tracker Example\n";
        cout << "3. Interactive Matrix Input\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                demonstrateBasics();
                break;
            case 2:
                demonstrateGradeTracker();
                break;
            case 3: {
                int matrix[ROWS][COLS];
                fillMatrix(matrix, ROWS);
                cout << "\nYour matrix:\n";
                printMatrix(matrix, ROWS);
                cout << "Sum of all elements: " << sumAll(matrix, ROWS) << endl;
                cout << "Maximum value: " << findMax(matrix, ROWS) << endl;
                break;
            }
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
} // end of main

// =========== demonstrateBasics ========================================
// Shows basic 2D array declaration, initialization, and access
//
// parameters: none
// output: none (displays to console)
// ======================================================================
void demonstrateBasics() {
    cout << "--- Basic 2D Array Demo ---\n\n";

    // Declaration and initialization
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Initialized matrix:\n";
    printMatrix(matrix, 3);

    // Accessing individual elements
    cout << "Accessing elements:\n";
    cout << "matrix[0][0] = " << matrix[0][0] << " (first element)\n";
    cout << "matrix[1][2] = " << matrix[1][2] << " (row 1, col 2)\n";
    cout << "matrix[2][3] = " << matrix[2][3] << " (last element)\n\n";

    // Modifying elements
    cout << "Changing matrix[1][1] from " << matrix[1][1] << " to 100\n";
    matrix[1][1] = 100;
    cout << "Modified matrix:\n";
    printMatrix(matrix, 3);

    // Sum operations
    cout << "Sum of all elements: " << sumAll(matrix, 3) << endl;
    cout << "Sum of row 0: " << sumRow(matrix, 3, 0) << endl;
    cout << "Sum of column 2: " << sumColumn(matrix, 3, 2) << endl;
    cout << "Maximum value: " << findMax(matrix, 3) << endl;
} // end of demonstrateBasics

// =========== demonstrateGradeTracker ==================================
// Shows a practical example using 2D arrays for student grades
//
// parameters: none
// output: none (displays to console)
// ======================================================================
void demonstrateGradeTracker() {
    cout << "--- Grade Tracker Demo ---\n\n";

    const int NUM_STUDENTS = 3;
    const int NUM_TESTS = 4;

    double grades[NUM_STUDENTS][NUM_TESTS] = {
        {85.5, 90.0, 78.5, 92.0},
        {76.0, 88.5, 95.0, 82.5},
        {90.0, 91.5, 89.0, 94.5}
    };

    // Display header
    cout << fixed << setprecision(1);
    cout << "\t\tTest 1\tTest 2\tTest 3\tTest 4\tAverage\n";
    cout << "----------------------------------------------------------------\n";

    // Display grades and calculate averages
    for (int s = 0; s < NUM_STUDENTS; s++) {
        cout << "Student " << s + 1 << ":\t";
        double sum = 0;

        for (int t = 0; t < NUM_TESTS; t++) {
            cout << grades[s][t] << "\t";
            sum += grades[s][t];
        }

        cout << sum / NUM_TESTS << endl;
    }

    // Calculate test averages (column sums)
    cout << "----------------------------------------------------------------\n";
    cout << "Test Avg:\t";
    for (int t = 0; t < NUM_TESTS; t++) {
        double sum = 0;
        for (int s = 0; s < NUM_STUDENTS; s++) {
            sum += grades[s][t];
        }
        cout << sum / NUM_STUDENTS << "\t";
    }
    cout << endl;
} // end of demonstrateGradeTracker

// =========== printMatrix ==============================================
// Displays a 2D integer array in grid format
//
// parameters: arr - the 2D array to display
//             rows - number of rows in the array
// output: none (displays to console)
// ======================================================================
void printMatrix(int arr[][COLS], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << setw(5) << arr[r][c];
        }
        cout << endl;
    }
    cout << endl;
} // end of printMatrix

// =========== fillMatrix ===============================================
// Fills a 2D array with user input
//
// parameters: arr - the 2D array to fill
//             rows - number of rows in the array
// output: none (modifies array through reference)
// ======================================================================
void fillMatrix(int arr[][COLS], int rows) {
    cout << "Enter " << rows * COLS << " integers:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << "Value for [" << r << "][" << c << "]: ";
            cin >> arr[r][c];
        }
    }
} // end of fillMatrix

// =========== sumAll ===================================================
// Calculates the sum of all elements in a 2D array
//
// parameters: arr - the 2D array
//             rows - number of rows
// output: int - the sum of all elements
// ======================================================================
int sumAll(int arr[][COLS], int rows) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            total += arr[r][c];
        }
    }
    return total;
} // end of sumAll

// =========== sumRow ===================================================
// Calculates the sum of a specific row
//
// parameters: arr - the 2D array
//             rows - number of rows (for bounds checking)
//             targetRow - the row index to sum
// output: int - the sum of the specified row
// ======================================================================
int sumRow(int arr[][COLS], int rows, int targetRow) {
    int total = 0;
    for (int c = 0; c < COLS; c++) {
        total += arr[targetRow][c];
    }
    return total;
} // end of sumRow

// =========== sumColumn ================================================
// Calculates the sum of a specific column
//
// parameters: arr - the 2D array
//             rows - number of rows
//             targetCol - the column index to sum
// output: int - the sum of the specified column
// ======================================================================
int sumColumn(int arr[][COLS], int rows, int targetCol) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        total += arr[r][targetCol];
    }
    return total;
} // end of sumColumn

// =========== findMax ==================================================
// Finds the maximum value in a 2D array
//
// parameters: arr - the 2D array
//             rows - number of rows
// output: int - the maximum value found
// ======================================================================
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
} // end of findMax

/* ====== output =======

===== 2D Array Demonstrations =====
1. Basic 2D Array Operations
2. Grade Tracker Example
3. Interactive Matrix Input
0. Exit
Enter choice: 1

--- Basic 2D Array Demo ---

Initialized matrix:
    1    2    3    4
    5    6    7    8
    9   10   11   12

Accessing elements:
matrix[0][0] = 1 (first element)
matrix[1][2] = 7 (row 1, col 2)
matrix[2][3] = 12 (last element)

Changing matrix[1][1] from 6 to 100
Modified matrix:
    1    2    3    4
    5  100    7    8
    9   10   11   12

Sum of all elements: 172
Sum of row 0: 10
Sum of column 2: 21
Maximum value: 100

*/
