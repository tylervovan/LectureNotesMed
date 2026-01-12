# Lecture 7: Functions

## Procedural Programming
- Organizes code into functions for reuse, efficiency, and clarity.
- C++ has built-in and programmer-defined functions.

## Anatomy of a Function

### 1. Function Prototype
Placed **above `main`**. Informs compiler of name, return type, and parameters.
```cpp
float calcPmt(float loanAmt, float rate);
```

### 2. Function Call
Invoked inside `main` (or other functions).
```cpp
monthlyPmt = calcPmt(loanAmt, rate);
```

### 3. Function Definition
The actual code. Usually placed **after `main`**.
```cpp
float calcPmt(float loanAmt, float rate) {
    return loanAmt * rate;
}
```

## Function Types

### Value-Returning Functions
Returns a single value. Used in assignment statements.
```cpp
int calcSquare(int num) {
    return num * num;
}
// Usage: int result = calcSquare(5);
```

### Void Functions
Does **not** return a value. Performs an action (e.g., output).
```cpp
void displayAge(int age) {
    cout << "Age: " << age << endl;
}
// Usage: displayAge(18);
```

## Parameters
- **Formal Parameter**: Variable declared in prototype/definition.
- **Actual Parameter (Argument)**: Value sent from call.

## Style Guidelines
- Function names: **camelCase**, command-like (e.g., `printLines`).
- Place comments above function headers.
- Separate functions with visual lines/space.
