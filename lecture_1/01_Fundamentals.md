# Lecture 1: C++ Fundamentals

## Computer Programs
- **Program**: A sequence of instructions that a computer executes.
- **High-level language**: Languages like C++ used by programmers.
- **Machine Language**: Binary code (1s and 0s) that computers understand.
- **Compiler**: Translates high-level code into machine language (e.g., Visual Studio, Xcode).

## Memory and Data
- **RAM (Random Access Memory)**: Main memory where programs are loaded for execution.
- **Byte**: Unit of data, 8 bits long (e.g., `01000001`).
- **Data**: Programs store data (text, numbers). 'A' is stored as `01000001`.

## Number Systems
### Overview
- **Decimal (Base 10)**: 0-9.
- **Binary (Base 2)**: 0 and 1. (1 = true, 0 = false).
- **Hexadecimal (Base 16)**: 0-9, A-F. One hex digit represents 4 bits.

### Conversions
#### Binary to Decimal
Sum powers of 2 where there is a '1'.
- *Example*: `01011011` = $64 + 16 + 8 + 2 + 1 = 91$.

#### Decimal to Binary
Find largest power of 2 $\le$ number, place '1', subtract, repeat.
- *Example*: $71 \rightarrow 01000111$.

#### Binary to Hexadecimal
Group into 4 bits from right to left.
- *Example*: `01011011` $\rightarrow$ `0101` (5) and `1011` (B) $\rightarrow$ `5B`.

#### Decimal to Hexadecimal
Decimal $\rightarrow$ Binary $\rightarrow$ Hexadecimal.
- *Example*: $26 \rightarrow 00011010 \rightarrow 1A$.

## The C++ Language and Compilation
### History
- Created at Bell Labs (~1985) as an extension of C.
- 1998: ANSI/ISO standard established.
- **C++11**: Significant update in 2011.

### The Compilation Process
1. **Source Code**: Programmer writes `.cpp` file.
2. **Compiler**: Translates to object file (`.obj`).
3. **Linker**: Combines `.obj` with libraries to create executable (`.exe`).
   - **Static Linking**: Library code copied into executable.
   - **Dynamic Linking**: Linking occurs at runtime.

## Visual Studio Setup and First Program
### Installation & Project Creation
1. Download **Visual Studio Community** (free).
2. File > New > Project... > **Win32 Console Application**.
3. Select **Empty Project**.
4. Right-click Source Files > Add > New Item > **C++ File (.cpp)**.

### Your First "Hello World" Program
```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello";
    return 0;
}
```

### Building and Running
- **Build**: Build > Build Solution.
- **Run**: Debug > Start Without Debugging.
