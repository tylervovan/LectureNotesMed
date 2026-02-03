# C++ Commenting Style Guide

When adding comments to C++ homework files, follow this format:

## File Header Comment
```cpp
// Attached: HW [number] ([all part letters / numbers in folder])
// =============================================================================
// Program: [program name]
// =============================================================================
//
// Programmer: [FULL NAME]
// Class: CS1B
// Instructor: Med Mogasemi
//
// =============================================================================
//
// Description:
// [Brief description of what the program does - 2-3 sentences max]
// =============================================================================
```

## Function Header Comments
```cpp
// =========== functionName =============================================
// Brief description of what the function does
//
// parameters: paramName - description of parameter
// output: returnType - description of what is returned (or "none" for void)
// ======================================================================
```

## Main Function Comment
The `main` function should always have an empty comment block (no description):
```cpp
// =========== main =====================================================
//
// ======================================================================
```

## Inline Comments
- Use `// end of functionName` after closing brace of each function
- Use `// comment` for brief inline explanations of non-obvious logic
- Comments should explain WHY, not WHAT (the code shows what)

## Output Section
```cpp
/* ====== output =======

[Paste sample program output here]

*/
```

## Git Commit Rules
- Do NOT include "Co-Authored-By: Claude" or any AI attribution in commit messages
