# Lecture 7: Functions

## CS terms: 


## Procedural Programming
- Organizes code into functions for reuse, efficiency, and clarity.
- C++ has built-in and programmer-defined functions.

## Anatomy of a Function

### 1. Function Prototype
Placed **above `main`**. Informs compiler of name, return type, and parameters.
```cpp
float calcPmt(float loanAmt, float rate);
```
`calcPmt` -> Function name also AKA the identifier 
`float` (at the beginning) -> return type (there can only be one return type) 
loanAmt -> *FORMAL PARAMETER* of the float type called loanAmt. `float` assigns the data type of the parameter

English of this code: I'm creating a function prototype with a float return data type called calcPmt. It has two formal parameters, loanAmt of the float data type and rate of the float data type. 

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
