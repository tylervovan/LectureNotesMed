# Lecture 5: Control Structures

## Selection Control Structures
Enables decisions (if/else).
- Always enclose bodies in braces `{}`.

### Relational Operators
Evaluate to `true` or `false` (bool).
- `==` (Equal to)
- `!=` (Not equal to)
- `<` (Less than)
- `>` (Greater than)
- `<=` (Less than or equal)
- `>=` (Greater than or equal)

### `if` Structures

**if statement**
```cpp
if (balance <= 0) {
    cout << "No money!";
}
```

**if-else statement**
```cpp
if ((num1 % 2) == 0) {
    cout << "Even";
} else {
    cout << "Odd";
}
```

**if-else if-else statement**
```cpp
if (score >= 90) {
    cout << "A";
} else if (score >= 80) {
    cout << "B";
} else {
    cout << "F";
}
```

## Logical Operators
Combine logical expressions.
- `!` (NOT): Inverts value.
- `&&` (AND): True only if both are true.
- `||` (OR): True if at least one is true.

```cpp
if ((character >= 'A') && (character <= 'Z')) {
    cout << "Uppercase letter";
}
```

### Operator Precedence (Highest to Lowest)
1. `!`, `+`, `-` (Unary)
2. `*`, `/`, `%`
3. `+`, `-`
4. `<`, `<=`, `>`, `>=`
5. `==`, `!=`
6. `&&`
7. `||`
8. `=` (Assignment)

## Switch Control Structure
Ideal for handling many alternatives based on a single **integral** value (`char`, `int`, `bool`).
- **`break`**: Exits the switch. Required to prevent "fall-through".
- **`default`**: Executes if no match found.

```cpp
switch (toupper(grade)) {
    case 'A':
        cout << "Good grade";
        break;
    case 'B':
        cout << "Pretty good";
        break;
    default:
        cout << "Invalid";
        break;
}
```

## Other Operators
### Ternary Operator (`?:`)
Shorthand for if-else.
```cpp
// (condition) ? if_true : if_false
int max = (num1 > num2) ? num1 : num2;
```

### Increment/Decrement
- **Prefix** (`++num`): Modified *before* use.
- **Postfix** (`num++`): Modified *after* use.

### Compound Assignment
- `sum += 5;` is `sum = sum + 5;`
- Also `-=`, `*=`, `/=`.
