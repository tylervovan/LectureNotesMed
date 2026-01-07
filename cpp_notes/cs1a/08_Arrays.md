# Lecture 8: Arrays

## Overview
- Represents a list or sequence of items.
- All elements must be of the **same data type**.
- **Zero-based indexing** (starts at 0).
- Size must be a **constant integer expression**.

## Declaration and Initialization
```cpp
// type identifier[size];
float scores[20];
```

### Initialization Options
1. **Assignment Statements**:
   ```cpp
   scores[0] = 25.50;
   scores[1] = 40.75;
   ```
2. **Initialization List**:
   ```cpp
   int myArray[5] = {1, 2, 3, 4, 5};
   // Remaining elements set to 0 if list is shorter than size
   int nums[50] = {1, 2, 3}; 
   ```

## Processing Arrays
Use loops (usually `for` loops) to access elements by index.

**Input Loop**:
```cpp
for (int i = 0; i < SIZE; i++) {
    cin >> grades[i];
}
```

**Sum/Average Loop**:
```cpp
for (int i = 0; i < SIZE; i++) {
    sum += grades[i];
}
```

## Important Notes
- **Uninitialized Arrays**: Not automatically set to 0 (contain garbage).
- **Index Out of Bounds**: Compiler may not catch `grades[20]` in a size 20 array (indices 0-19), but it causes runtime errors/memory corruption.
- **Copying**: Cannot do `array1 = array2;`. Must copy element by element.
- **Comparison**: Cannot do `array1 == array2;`. Compare element by element.

## Arrays and Functions
Arrays are passed by reference (address of first element).
- **Prototype**: `void func(int arr[], int size);`
- **Call**: `func(myArray, SIZE);` (No brackets in call).

```cpp
void displayArray(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
}
```
