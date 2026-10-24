# C++ Programming Guide: From Basics to Advanced

## Table of Contents

1. [Introduction to C++](#introduction-to-c)
2. [Basic Syntax and Structure](#basic-syntax-and-structure)
3. [Compiling and Running a C++ Program](#compiling-and-running-a-c-program)
4. [C++ Input and Output Streams](#c-input-and-output-streams)
5. [Data Types](#data-types)
6. [Operators and Precedence](#operators-and-precedence)
7. [Control Structures](#control-structures)
8. [Type Conversion and Casting](#type-conversion-and-casting)
9. [Functions](#functions)
10. [Arrays and Strings](#arrays-and-strings)
11. [References and Pointers](#references-and-pointers)
12. [Memory Management](#memory-management)
13. [Structures, Unions, and Enums](#structures-unions-and-enums)
14. [Object-Oriented Programming](#object-oriented-programming)
15. [Inheritance](#inheritance)
16. [Polymorphism](#polymorphism)
17. [Templates](#templates)
18. [Exception Handling](#exception-handling)
19. [File I/O](#file-io)
20. [Standard Template Library (STL)](#standard-template-library-stl)
21. [Advanced Concepts](#advanced-concepts)

---

## Introduction to C++

C++ is a powerful, high-performance programming language that supports both procedural and object-oriented programming paradigms. It's widely used for system programming, game development, embedded systems, and high-performance applications.

### Key Features:

- **Object-Oriented**: Supports classes, inheritance, polymorphism
- **Performance**: Low-level memory control, compiled language
- **Standard Library**: Rich set of containers, algorithms, and utilities
- **Cross-Platform**: Runs on multiple operating systems
- **Backward Compatible**: Can use C code

---

## Basic Syntax and Structure

### 1. `#include <iostream>`

**What it is:** `iostream` stands for "input/output stream". Header file inclusion for input/output operations. It contains definitions for reading input from the user (using `cin`) and displaying output on the screen (using `cout`). Without this, we cannot use `cout` to print text.

- Always include necessary headers at the top
- `iostream` provides `cin`, `cout`, `endl`
- Compilation fails without required headers
- Use angle brackets `<>` for standard library headers

### 2. `using namespace std;`

**What it is:** Directive to use the standard namespace.

**Why we use it:** In C++, `std` is the **standard namespace** where common functions and objects like `cout`, `cin`, `endl`, etc. are defined.

**Without it:** You would need to write `std::cout` instead of just `cout` every time.

- Avoid in header files to prevent name conflicts
- Allows shorter code (cout vs std::cout)
- Can lead to ambiguity if multiple namespaces have same names
- Consider using specific declarations: `using std::cout;`

### 3. `int main()`

**What it is:** Entry point function for C++ programs.

- Required in every C++ program
- OS calls main() first
- Return type `int` indicates success/failure
- Can take command-line arguments: `int main(int argc, char* argv[])`

**Parameters**: Can take command-line arguments:

```cpp
int main(int argc, char* argv[]) {
    // argc: number of arguments
    // argv: array of argument strings
    return 0;
}
```

### 4. `return 0;`

**What it is:** Exit status return to the operating system. A return statement tht exits the main function.

\*What 0 means:\*\*

- `0` = Program executed successfully (no errors)
- Non-zero (like `1`) = Program encountered an error

- 0 = success, non-zero = error
- The operating system checks this return value
- Other programs can detect if your program ran successfully
- In shell scripts, you can check if a program succeeded using the exit code

### Summary Table

| Part                   | Purpose                                                       | Key Reminder          |
| ---------------------- | ------------------------------------------------------------- | --------------------- |
| `#include <iostream>`  | Include input/output library                                  | Required for cin/cout |
| `using namespace std;` | Use standard namespace (allows `cout` instead of `std::cout`) | Avoid in headers      |
| `int main()`           | Entry point of the program                                    | Must return int       |
| `cout << "hello ";`    | Print text to screen                                          | Use endl for newlines |
| `return 0;`            | Return success to operating system                            | 0 = success           |

---

## Compiling and Running a C++ Program

Compiling a C++ source file translates it into an executable program; it does
not run the program or display output produced by `cout`. To see that output,
compile the source first, then run the executable.

### What happens during compilation?

For a command such as `g++ main.cpp -o my_program`, the toolchain generally:

1. **Preprocesses** directives such as `#include` and expands macros; comments
   are removed during translation.
2. **Compiles** the preprocessed C++ into lower-level instructions, commonly
   represented as assembly.
3. **Assembles** those instructions into object code.
4. **Links** object code with any required libraries to create the executable
   `my_program`.

These are conceptual stages; a compiler may combine them or use temporary files
without writing each intermediate result to disk.

### Compile, then run

```bash
g++ main.cpp -o my_program
./my_program
```

The first command builds the executable. If it succeeds, it usually returns to
the shell prompt without output, though the compiler may print warnings. Errors
are reported by the compiler or linker. The second command runs the executable;
that is when output from statements such as `std::cout` appears in the terminal.
The `./` prefix tells the shell to run `my_program` from the current directory.

For example:

```text
$ g++ main.cpp -o my_program
$ ./my_program
Hello World!
```

---

## C++ Input and Output Streams

`std::cin` and `std::cout` handle common terminal input and output, but C++
streams also work with files and in-memory strings. The stream operators
`>>` and `<<` provide a consistent interface for many data types and
destinations.

### `std::cin` and `std::cout` are stream objects

`std::cin` and `std::cout` are standard-library objects provided by
`<iostream>`, not functions or data types. `std::cin` has type `std::istream`
(an alias for `std::basic_istream<char>`), and `std::cout` has type
`std::ostream` (an alias for `std::basic_ostream<char>`).

The operators used with streams are overloaded for stream types. For example,
`std::cout << "Hello";` calls an appropriate `operator<<` overload; it is not
necessarily a member function called directly on `std::cout`.

Stream objects also provide member functions:

```cpp
char ch;
if (std::cin.get(ch)) {    // Read one character, including whitespace
    std::cout.put(ch);     // Write one character
}

if (!std::cin) {
    std::cin.clear();      // Reset error state; does not remove invalid input
}
```

### Terminal input and output

```cpp
#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    if (std::cin >> age) {
        std::cout << "Age: " << age << '\n';
        std::cout.put('!');
    }
}
```

Unlike formatted C functions such as `printf` and `scanf`, streams do not
require format specifiers for each value. C-style I/O is still available
through `<cstdio>` (for example, `std::printf` and `std::scanf`); performance
depends on the program and should be measured rather than assumed.

### Read a full line

Formatted extraction with `>>` stops at whitespace. Use `std::getline` to read
a whole line, including spaces:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string full_name;
    std::cout << "Enter your full name: ";
    if (std::getline(std::cin, full_name)) {
        std::cout << "Hello, " << full_name << '\n';
    }
}
```

When calling `std::getline` after `std::cin >> value`, the newline left in the
input buffer may be read as an empty line. Consume that newline first when
appropriate.

### File streams (`<fstream>`)

Use `std::ofstream` to write a file and `std::ifstream` to read one. These
stream objects close their files automatically when they go out of scope.
Check that opening or reading succeeds:

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    {
        std::ofstream out_file("example.txt");
        if (!out_file) {
            std::cerr << "Could not open file for writing\n";
            return 1;
        }
        out_file << "Writing text to a file.\n";
    }

    std::ifstream in_file("example.txt");
    if (!in_file) {
        std::cerr << "Could not open file for reading\n";
        return 1;
    }

    std::string line;
    if (std::getline(in_file, line)) {
        std::cout << "File content: " << line << '\n';
    }
}
```

See [File I/O](#file-io) for more file-handling examples.

### String streams (`<sstream>`)

`std::stringstream` treats a string as a stream, which is useful for parsing
values from text or formatting values into text in memory:

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream input("Alice 25 98.5");
    std::string name;
    int age;
    double score;

    if (input >> name >> age >> score) {
        std::cout << name << " is " << age
                  << " years old; score: " << score << '\n';
    }
}
```

### C and C++ I/O at a glance

| Task                           | C-style I/O                 | C++ streams                      |
| ------------------------------ | --------------------------- | -------------------------------- |
| Terminal output                | `printf`, `puts`, `putchar` | `std::cout`, `std::cout.put`     |
| Terminal input                 | `scanf`, `getchar`, `fgets` | `std::cin`, `std::getline`       |
| File access                    | `FILE*`, `fopen`, `fprintf` | `std::ifstream`, `std::ofstream` |
| Parse or format text in memory | `sscanf`, `sprintf`         | `std::stringstream`              |

Both C and C++ I/O are available in C++ programs. Avoid mixing them on the
same standard stream unless you understand stream synchronization and buffering.

---

## Data Types

### Data Types

**What they are:** Built-in types for storing simple values.

| Type group     | Fundamental types                                                           | Purpose                                                                        |
| -------------- | --------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| Boolean        | `bool`                                                                      | Represents `true` or `false`.                                                  |
| Character      | `char`, `signed char`, `unsigned char`, `wchar_t`, `char16_t`, `char32_t`   | Stores character code units. `char8_t` is also available since C++20.          |
| Integer        | `short`, `int`, `long`, `long long`, each optionally `signed` or `unsigned` | Represents whole numbers; `signed` is the default for these types.             |
| Floating-point | `float`, `double`, `long double`                                            | Represents real-number approximations with different minimum precision ranges. |
| No value       | `void`                                                                      | Indicates no value, such as a function that returns nothing.                   |
| Null pointer   | `std::nullptr_t`                                                            | The type of the `nullptr` literal; available via `<cstddef>`.                  |

The character and integer types have implementation-dependent sizes and
ranges, subject to standard minimum requirements. Plain `char` is a distinct
type from `signed char` and `unsigned char`; whether it behaves as signed or
unsigned is implementation-defined. `char8_t` requires C++20 or later.

`std::string` is not a fundamental type. It is a standard-library class for
working with text and is declared in `<string>`.

### `std::size_t`

`std::size_t` is an unsigned integer type used to represent the size of an
object in bytes and the sizes of arrays and containers. It is declared in
`<cstddef>`. Some headers also make `size_t` available in the global
namespace, but `std::size_t` is the portable spelling when including
`<cstddef>`.

The exact underlying type and width are implementation-dependent. It is
guaranteed to be large enough to represent the size in bytes of any object,
but it is not guaranteed to have a particular width on every architecture.
The `sizeof` operator returns `std::size_t`. Container `.size()` functions
return that container's `size_type`, which is commonly `std::size_t` but is
not required to be the same type.

Use the container's `size_type`, `auto`, iterators, or a range-based loop when
appropriate. For example:

```cpp
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string text = "Hello";
    std::vector<int> numbers = {10, 20, 30};

    for (std::size_t i = 0; i < text.size(); ++i) {
        std::cout << text[i] << ' ';
    }

    for (const auto& number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << "\nSize of numbers object: "
              << sizeof(numbers) << " bytes\n";
}
```

`sizeof(numbers)` reports the size of the vector object itself, not the memory
used by its dynamically allocated elements.

Because `std::size_t` is unsigned, subtracting one from zero wraps to its
maximum value. Avoid conditions such as `i >= 0` in a countdown loop. A safe
reverse-index pattern is:

```cpp
for (std::size_t i = numbers.size(); i > 0; --i) {
    std::cout << numbers[i - 1] << ' ';
}
```

### I/O Manipulators

**`boolalpha` and `noboolalpha`:**

- `boolalpha`: Makes cout print booleans as "true"/"false"
- `noboolalpha`: Reverts to 1/0 (default)

- `boolalpha` is not a data type. It is an I/O manipulator - a setting that changes how cout displays boolean values. When you use it, you are telling cout: "`From now on, print booleans as true and false instead of 1 and 0`."
- If you want to go back to the default behavior (printing 1 and 0), you can use `noboolalpha`.

- Include `<iomanip>` for manipulators
- Affects all subsequent boolean output
- Use `cout << boolalpha << myBool;`

### Variable Declaration and Initialization

```cpp
// Declaration
int x;

// Initialization
int y = 10;

// Multiple declarations
int a, b, c = 5;

// Constants
const int MAX_SIZE = 100;
const double PI = 3.14159;

// Type inference (C++11+)
auto value = 42;  // int
auto pi = 3.14;   // double
```

### Data Type Categories

**Fundamental Data Types:** Built-in types such as `bool`, the character,
integer, and floating-point types, `void`, and `std::nullptr_t`.

**Derived Data Types:** Created from basic types [array, pointer, reference, function]

**User-Defined Types:** Custom types such as classes, structs, unions, and enums.

- Basic types are fundamental building blocks
- Derived types extend functionality
- User-defined types allow complex data structures
- Choose based on your data requirements

### ASCII Values

**Character ranges:**

- [a-z]: [97-122]
- [A-Z]: [65-90]
- [0-9]: [48-57]

- Useful for character arithmetic
- Case conversion: add/subtract 32
- Character classification without cctype functions

### Keywords

**`auto`:** Automatic type deduction (C++11+). Only works when you assign a avalue at the decalaration.

- Must initialize when declaring with auto
- Compiler infers type from initializer
- Useful for complex types: `auto result = someFunction();`

---

## Operators and Precedence

### Arithmetic Operators

**Operators:** + - \* / % ++ --

- Division of integers truncates (5/2 = 2)
- Modulo (%) works with integers only
- Increment/decrement: prefix (++i) vs postfix (i++)
- Watch for overflow with large numbers

```cpp
int a = 10, b = 3;
cout << a + b << endl;  // 13
cout << a - b << endl;  // 7
cout << a * b << endl;  // 30
cout << a / b << endl;  // 3 (integer division)
cout << a % b << endl;  // 1 (modulo)
```

### Assignment Operators

**Operators:** = += -= \*= /= %= &= |= ^= >>= <<=

- Compound assignments are efficient
- Right-associative: a = b = c means a = (b = c)
- Don't confuse = with == in conditions

```cpp
int x = 5;
x += 3;  // x = x + 3 → 8
x *= 2;  // x = x * 2 → 16
```

### Relational Operators

**Operators:** == != < > <= >=

- Return bool (true/false)
- == checks equality, = assigns
- Floating point comparisons may have precision issues
- Use epsilon for float comparisons

```cpp
// Return bool: true/false
5 == 5   // true
5 != 3   // true
5 < 3    // false
5 > 3    // true
5 <= 5   // true
5 >= 6   // false
```

### Logical Operators

**Operators:** && || !

- Short-circuit evaluation: `&& stops if first operand false`
- `|| stops if first operand true`
- ! has higher precedence than comparison operators

```cpp
bool a = true, b = false;
a && b  // false (AND)
a || b  // true (OR)
!a      // false (NOT)
```

### Increment/Decrement

```cpp
int x = 5;
x++;     // Post-increment: x becomes 6
++x;     // Pre-increment: x becomes 7
x--;     // Post-decrement: x becomes 6
--x;     // Pre-decrement: x becomes 5
```

### Operator Precedence (High to Low)

1. `()` `[]` `->` `.` (postfix)
2. `!` `~` `++` `--` (unary)
3. `*` `/` `%` (multiplication)
4. `+` `-` (addition)
5. `<<` `>>` (shift)
6. `<` `<=` `>` `>=` (relational)
7. `==` `!=` (equality)
8. `&` (bitwise AND)
9. `^` (bitwise XOR)
10. `|` (bitwise OR)
11. `&&` (logical AND)
12. `||` (logical OR)
13. `?:` (ternary)
14. `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=` `^=` `>>=` `<<=` (assignment)

- Parentheses override precedence
- Multiplication/division before addition/subtraction
- Logical operators have lower precedence than relational
- Use parentheses for clarity when unsure

---

## Control Structures

### Conditional Statements

#### if-else

```cpp
if (condition) {
    // true block
} else if (another_condition) {
    // another block
} else {
    // false block
}
```

- Condition must evaluate to bool
- else if chains for multiple conditions
- Braces required for multi-statement blocks

#### switch-case

```cpp
switch (expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code
}
```

- Expression must be int, char, or enum
- Cases must be constant values
- break prevents fall-through
- default handles unmatched cases

#### Ternary Operator

```cpp
result = condition ? true_value : false_value;
```

- Shorthand for simple if-else
- Can be nested but avoid for readability
- All operands are evaluated

### Loops

#### for loop

The classic `for` loop has three parts: initialization, a condition, and an
update. It is useful when you need an index or custom stepping:

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << i << ' ';
}
```

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};
    for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i) {
        std::cout << "Index " << i << ": " << numbers[i] << '\n';
    }
}
```

The initialization runs once, the condition is checked before each iteration,
and the update runs after each iteration. Use the container's `size_type` for
an index that is compared with its `.size()`.

The following loop fragments assume `numbers` is a `std::vector<int>` in
scope.

#### Range-based for loop (C++11+)

A range-based loop visits each element without requiring an index. Declaring
the loop variable by value makes a copy:

```cpp
for (int number : numbers) {
    std::cout << number << ' ';
}
```

Use a non-const reference to modify the original elements, or a const reference
to avoid copying when you only need to read them:

```cpp
for (int& number : numbers) {
    number *= 2;
}

for (const int& number : numbers) {
    std::cout << number << ' ';
}
```

An `int&` is a reference, not a pointer. For small types such as `int`, copying
may be just as efficient; references are especially useful for larger objects
or when changes should affect the original elements.

#### Iterator-based loop

Iterators provide a general way to traverse standard-library containers. Use
`auto` to avoid spelling out a potentially long iterator type:

```cpp
for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << ' ';
}
```

When erasing elements during traversal, use the iterator returned by `erase`.
For `std::vector`, erasing invalidates iterators at and after the erased
element:

```cpp
for (auto it = numbers.begin(); it != numbers.end();) {
    if (*it == 20) {
        it = numbers.erase(it);
    } else {
        ++it;
    }
}
```

Choose an iteration pattern based on whether you need an index, want to modify
elements, or need to insert or erase elements. Iterator invalidation rules vary
by container.

#### Other `for` loop forms

The three parts of a classic `for` loop are flexible. Omitting them creates an
infinite loop, which should normally exit with `break` or another control-flow
statement:

```cpp
bool should_stop = true;
for (;;) {
    if (should_stop) {
        break;
    }
}
```

You can initialize and update multiple variables using comma-separated
expressions:

```cpp
for (int i = 0, j = 10; i < j; ++i, --j) {
    std::cout << i << ", " << j << '\n';
}
```

The initialization and update may also be omitted when handled elsewhere:

```cpp
int i = 1;
for (; i <= 3;) {
    std::cout << i << ' ';
    ++i;
}
```

Loops can be nested to process rows and columns:

```cpp
for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 3; ++col) {
        std::cout << '(' << row << ", " << col << ") ";
    }
    std::cout << '\n';
}
```

#### while loop

```cpp
while (condition) {
    // code
}
```

- Condition checked before entering loop
- May not execute if condition false initially

#### do-while loop

```cpp
do {
    // code
} while (condition);
```

- Executes at least once
- Condition checked after execution

### Jump Statements

**`break`:** Exit the nearest enclosing loop or `switch` statement. Execution
continues after that loop or switch.

**`continue`:** Skip to the next iteration of the nearest enclosing loop.

**`return`:** Exit the current function immediately and return control to its
caller. A non-`void` function can return a value.

```cpp
void check_numbers() {
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) {
            break;
        }
        std::cout << i << ' ';
    }
    std::cout << "\nLoop ended; the function is still running.\n";
}
```

Use `break` when only the loop or switch should stop; use `return` when the
function itself should finish.

**`goto`:** Jump to a labeled statement in the same function. It can make
control flow difficult to follow, so prefer structured loops and functions.

```cpp
void demonstrate_goto() {
    goto cleanup;

cleanup:
    std::cout << "Cleanup point\n";
}
```

Avoid jumping over declarations with initialization or into scopes where local
variables would be bypassed; such jumps are ill-formed in C++.

---

## Type Conversion and Casting

`Type conversion` means converting one type of data to another compatible type such that it doesn’t lose its meaning. It is essential for managing different data types in C++.

### Implicit vs Explicit Conversion

**Implicit:** Automatic conversion by compiler (safe conversions)

**Explicit:** Manual conversion using cast operators

- Implicit conversions can lose data (double to int)
- Explicit casts tell compiler "I know what I'm doing"
- Old C-style casts are unsafe and deprecated

### C++ Cast Operators

`Cast operator` is an unary operator which forces one data type to be converted into another data type. C++ supports four types of casting:

1. **Static Cast:** Standard compile-time conversions
   - Safe for related types
   - No runtime overhead

2. **Dynamic Cast:** Runtime type checking in inheritance
   - For polymorphic classes
   - Returns nullptr if cast fails

3. **Const Cast:** Add/remove const qualifier
   - Dangerous, use carefully
   - Can break const-correctness

4. **Reinterpret Cast:** Low-level bit reinterpretation
   - Very dangerous
   - For pointers to unrelated types

- Prefer static_cast for basic conversions
- Use dynamic_cast for safe downcasting
- Avoid const_cast unless absolutely necessary
- Reinterpret_cast is rarely needed and dangerous

---

## Functions

### Function Basics

**Declaration:** `return_type function_name(parameters);`

**Definition:** `return_type function_name(parameters) { body }`

- Functions must be declared before use
- Parameters are passed by value by default
- Return type void for no return value
- Functions can be overloaded

#### Free functions

A free function is declared outside a class or namespace member scope. Its
declaration (also called a prototype) lets code call it before its definition:

```cpp
#include <iostream>

int multiply(int a, int b);  // Declaration

int main() {
    std::cout << multiply(4, 5) << '\n';
}

int multiply(int a, int b) {  // Definition
    return a * b;
}
```

A function can also be defined before `main`, in which case that definition
serves as its declaration.

#### Member functions

Member functions are declared in a class or struct and are associated with
that type:

```cpp
class Calculator {
public:
    int add(int a, int b) const {
        return a + b;
    }
};
```

#### Function templates

Function templates describe a family of functions for different types. The
compiler can deduce the template argument from a call when possible:

```cpp
template <typename T>
T max_value(T a, T b) {
    return a > b ? a : b;
}
```

For example, `max_value(5, 10)` uses `T` as `int`. Both arguments must deduce
compatible template arguments unless a type is specified explicitly or the
template allows different types.

#### Lambda Functions (C++11+)

Lambdas are unnamed function objects that can optionally capture variables from their surrounding scope. They are useful for short operations and callbacks:

**What it is:** Anonymous functions defined inline.

**Syntax:** `[capture](parameters) { body }`

```cpp
int offset = 2;
auto add_offset = [offset](int value) {
    return value + offset;
};
```

- Useful for short, one-time functions
- Capture variables from surrounding scope
- Can be assigned to variables or passed to functions
- Modern alternative to function pointers

```cpp
auto lambda = [](int x) { return x * 2; };
cout << lambda(5) << endl;  // 10
```

#### Trailing return types (C++11)

A trailing return type places the return type after the parameter list. It is
available since C++11 and can be useful when the return type depends on the
parameter types:

```cpp
auto add(double a, double b) -> double {
    return a + b;
}
```

#### `inline` functions

The `inline` specifier does not require the compiler to replace a function call with the function body; that optimization is up to the compiler. It also permits equivalent definitions of the same inline function in multiple translation units, which is useful for functions defined in headers.

```cpp
inline int square(int value) {
    return value * value;
}
```

### Parameter Passing

#### Pass by Value:

Function gets a copy

```cpp
void func(int x) { x = 10; } // Original unchanged
```

#### Pass by Reference

Function modifies original

```cpp
void func(int& x) { x = 10; } // Original changed
```

#### Pass by Pointer

Similar to reference but can be null

```cpp
void func(int* x) { *x = 10; } // Original changed
```

- Use references for efficiency and modification
- Use pointers when null is a valid state
- Const references prevent modification: `const int& x`

### Default Arguments

Default arguments provide values for trailing parameters when the caller omits them. Put the default in the declaration visible to the caller; do not repeat it in a later definition.

```cpp
void print(int x, int y = 0);

void print(int x, int y) {
    std::cout << x << ' ' << y << '\n';
}

int main() {
    print(5);      // Uses y = 0
    print(5, 10);  // Uses y = 10
}
```

### Functions in Arrays and Structures

**Arrays:** Passed as pointers (decay to pointers). Pass array as function parameter.

```cpp
void func(int arr[]) { /* size lost */ }
```

**Structures:** Passed by value (copy) or reference

```cpp
void func(MyStruct s) { /* copy */ }
void func(MyStruct& s) { /* reference */ }
```

- Array size is lost when passed to function
- Pass structures by reference to avoid copying
- Use const for parameters you don't modify
- pass structure by reference to a function - Since the structure is passed by value, the function gets a copy of the structure. This means that the original data is not changed.

### Function Overloading

Function overloading allows functions in the same scope to share a name when
their parameter lists differ. Overloads can differ by the number, types, or
order of parameter types. The compiler selects an overload based on the call's
arguments.

```cpp
#include <iostream>

class PrintData {
public:
    void print(int value) {
        std::cout << "int: " << value << '\n';
    }

    void print(double value) {
        std::cout << "double: " << value << '\n';
    }

    void print(int first, int second) {
        std::cout << first << " and " << second << '\n';
    }
};

int main() {
    PrintData data;
    data.print(5);
    data.print(3.14);
    data.print(10, 20);
}
```

Return type alone cannot distinguish overloads. Overloads can also become
ambiguous when more than one is an equally good match after conversions.

### Virtual Functions

**What it is:** Functions that can be overridden in child classes.

- Declared with `virtual` in base class
- Enables runtime polymorphism
- Without virtual: early binding (compile-time) - C++ decides which function to call based on the pointer type, not the actual object type.
- With virtual: late binding (runtime) - it checks the actual object the pointer is pointing to.
- Use override keyword in derived classes

---

## Arrays and Strings

### Arrays

The examples below use standard-library facilities; include the corresponding
headers such as `<iostream>`, `<string>`, `<cstddef>`, `<array>`, and
`<vector>` in a complete program.

#### Integer Array

```cpp
// One-dimensional int arrays
int arr[5];                    // Fixed size; local elements are uninitialized
int a[5] = {1, 2, 3, 4, 5};   // Initialize every element
int b[] = {1, 2, 3};           // Size inferred as 3
int c[5] = {1, 2};             // Remaining elements are zero
int d[5] = {};                 // All elements are zero
int e[] = {0};                 // One element: 0

// Accessing elements
cout << a[0] << endl;  // First element

// Multi-dimensional
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

An uninitialized local array such as `int arr[5];` contains indeterminate values. A local `static` array and a global array are zero-initialized:

```cpp
void example() {
    static int values[5];  // Zero-initialized; retains its values between calls
}

int globalValues[5];       // Zero-initialized
```

#### Character array and String array

```cpp
char letters[3] = {'C', '+', '+'}; // Three characters; not a C-style string
char word[] = "cat";               // Four chars, including the '\0' terminator

std::string names[2] = {"Ada", "Lin"};
```

Use `std::string` for text when possible. A C-style string is a `char` array terminated by `'\0'`; it needs room for that extra terminator. Do not modify a string literal through a `char*`.

#### Pointers to arrays

An array name usually converts (decays) to a pointer to its first element. That pointer does not store the array length:

```cpp
int values[3] = {10, 20, 30};
int* element_ptr = values;          // Points to values[0]
int* same_ptr = &values[0];

std::cout << *element_ptr << '\n';      // 10
std::cout << *(element_ptr + 1) << '\n'; // 20
```

A pointer to an element (`int*`) is different from a pointer to the whole array (`int (*)[3]`):

```cpp
int values[3] = {10, 20, 30};
int (*array_ptr)[3] = &values;  // Parentheses are important
std::cout << (*array_ptr)[1] << '\n';  // 20
```

#### Arrays and vectors of different element types

Built-in arrays have a fixed size. The same syntax works for arrays of integers, characters, strings, and pointers:

```cpp
int numbers[3] = {10, 20, 30};
char letters[] = {'H', 'i'};          // Not null-terminated
char word[] = "Hi";                   // Includes the '\0' terminator
std::string names[2] = {"Ada", "Lin"};

int first = 5;
int second = 10;
int* pointers[2] = {&first, &second}; // Non-owning pointers to existing ints
```

`std::vector` is a resizable standard-library container for elements of one type. It can also hold pointers, but a vector of pointers does not own the objects they point to:

```cpp
#include <string>
#include <vector>

int first = 5;
int second = 10;
std::vector<int> number_vector = {10, 20, 30};
std::vector<char> letter_vector = {'H', 'i'};
std::vector<std::string> name_vector = {"Ada", "Lin"};
std::vector<int*> pointer_vector = {&first, &second};
```

Ensure pointed-to objects remain alive for as long as you use pointers stored in an array or vector. Prefer storing values directly, or use smart pointers when the container should own dynamically allocated objects.

Prefer a fixed-size array, `std::array`, or `std::vector` over manually allocated arrays. If using `new[]`, pair it with `delete[]`; in modern code, standard containers usually manage storage more safely.

#### Passing arrays to functions

A built-in array passed as `int values[]` or `int* values` becomes a pointer parameter, so the function cannot determine the array length from that parameter. Pass the length separately:

```cpp
void print_values(const int* values, std::size_t count) {
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << values[i] << ' ';
    }
}
```

To preserve a built-in array's size in the type, pass it by reference. This form accepts arrays of exactly three `int`s:

```cpp
void print_three(const int (&values)[3]) {
    for (int value : values) {
        std::cout << value << ' ';
    }
}
```

A function template can deduce the built-in array size:

```cpp
template <std::size_t N>
void print_array(const int (&values)[N]) {
    for (int value : values) {
        std::cout << value << ' ';
    }
}
```

For `std::array`, pass by reference to avoid copying and preserve its size.
For `std::vector`, pass by reference as well; use `const` when the function only reads it:

```cpp
void print_fixed(const std::array<int, 3>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
}

void print_dynamic(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
}
```

Arrays of pointers can be passed similarly. This function prints the pointed-to integers; it checks for null pointers before dereferencing:

```cpp
void print_pointers(int* const values[], std::size_t count) {
    for (std::size_t i = 0; i < count; ++i) {
        if (values[i] != nullptr) {
            std::cout << *values[i] << ' ';
        } else {
            std::cout << "(null) ";
        }
    }
}
```

Use a const reference for a vector of pointers when the function only reads the vector:

```cpp
void print_pointer_vector(const std::vector<int*>& values) {
    for (const int* value : values) {
        if (value != nullptr) {
            std::cout << *value << ' ';
        } else {
            std::cout << "(null) ";
        }
    }
}
```

The array/vector is not copied, but these pointers still do not own their integers.

For a two-dimensional built-in array, all dimensions except the first must be
specified in a pointer-style parameter:

```cpp
void print_matrix(const int matrix[][3], std::size_t rows) {
    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < 3; ++col) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << '\n';
    }
}
```

#### Printing arrays

Built-in arrays do not have a general `std::cout` output operation. Use a loop, such as a range-based loop, or write a helper function:

```cpp
for (int value : scores) {
    std::cout << value << ' ';
}
```

Writing a null-terminated `char` array to `std::cout` prints it as text. Writing a non-null-terminated character array this way is unsafe because the stream keeps reading until it finds a `'\0'`. Use a loop to print individual
characters instead. `std::array` and `std::vector` also need a loop or another explicit formatting method.

#### Returning arrays from functions

A function cannot return a built-in array by value. For a fixed-size result,
return `std::array`; for a result whose length can vary, return `std::vector`.
Both can be returned by value:

```cpp
#include <array>
#include <vector>

std::array<int, 3> make_fixed_values() {
    return {10, 20, 30};
}

std::vector<int> make_values() {
    return {10, 20, 30};
}
```

Returning a pointer to a local built-in array is not safe: the local array stops existing when the function returns. Prefer returning a standard container by value.

### Strings

#### C-style Strings

```cpp
char str[] = "Hello";
char str2[20];
strcpy(str2, "World");
```

#### std::string (Recommended)

```cpp
#include <string>

string s1 = "Hello";
string s2 = "World";
string combined = s1 + " " + s2;  // "Hello World"

cout << s1.length() << endl;      // 5
cout << s1.substr(0, 3) << endl;  // "Hel"
```

### Common String Operations

```cpp
string s = "Hello World";

// Length
s.length();

// Find substring
size_t pos = s.find("World");

// Replace
s.replace(pos, 5, "Universe");

// Split string(manual)
vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
```

---

## References and Pointers

### References

**What it is:** An alias for an existing variable. It is created using the & operator.

**Syntax:** `type& ref = variable;`

- Must be initialized when declared
- Cannot be null
- Cannot be reassigned to refer to another variable
- Use for function parameters to avoid copying

```cpp
int x = 10;
int& ref = x;  // Reference to x

ref = 20;      // Changes x to 20
cout << x << endl;  // 20
```

### Pointers

**What it is:** A variable that stores memory address.

**Syntax:** `type* ptr = &variable;`

- Declaration: `int* ptr;` creates pointer variable
- Dereference: `*ptr` accesses the value at address
- Can be null: `int* ptr = nullptr;`
- Pointer arithmetic: `ptr + 1` moves to next element

```cpp
int x = 10;
int* ptr = &x;     // Pointer to x

cout << ptr << endl;   // Address of x
cout << *ptr << endl;  // Value at address (10)

// Pointer arithmetic
int arr[] = {1, 2, 3};
int* p = arr;
cout << *p << endl;     // 1
cout << *(p + 1) << endl; // 2
```

### Pointer Types

Pointers can be classified by what they point to, their `const` qualifications,
and whether they own the pointed-to object.

The examples use standard-library facilities; include headers such as
`<iostream>`, `<memory>`, and `<utility>` in a complete program.

#### Uninitialized, null, and dangling pointers

An uninitialized pointer has an indeterminate value. Do not read or dereference
it before assigning it a valid address:

```cpp
int* uninitialized_ptr;  // Do not use until initialized
int* null_ptr = nullptr; // Explicitly points to no object
```

Dereferencing a null pointer is invalid. C++11 and later provide `nullptr`,
which is type-safe and preferred to the older `NULL` macro. C code commonly
uses `NULL` to represent a null pointer.

A dangling pointer refers to an object whose lifetime has ended, or to
storage that has been released. Dereferencing it is undefined behavior:

```cpp
int* dangling_ptr = new int(42);
delete dangling_ptr;
dangling_ptr = nullptr;  // Clears this pointer; other copies would still dangle
```

Setting a pointer to `nullptr` after releasing an object can prevent accidental
use through that pointer, but it does not repair any other dangling copies.
Prefer automatic lifetime management or smart pointers where possible.

#### Object pointers and pointer qualification

An object pointer points to an object. `const` can qualify the pointed-to
object, the pointer itself, or both:

```cpp
int value = 10;
int other = 20;

int* ptr = &value;                    // Can change value and be redirected
const int* ptr_to_const = &value;     // Cannot change value through this pointer
int* const const_ptr = &value;        // Cannot redirect this pointer
const int* const fixed_ptr = &value;  // Cannot change either through this pointer

ptr_to_const = &other; // OK
*const_ptr = 11;       // OK
```

`const int*` means “pointer to const int”; `int* const` means “const pointer
to int.”

#### Void pointers

`void*` can hold the address of an object of an unknown type, but cannot be
dereferenced directly. Convert it back to the correct object-pointer type
before use:

```cpp
int value = 10;
void* raw_ptr = &value;
int* int_ptr = static_cast<int*>(raw_ptr);
std::cout << *int_ptr << '\n';
```

#### Pointer-to-pointer

A pointer-to-pointer stores the address of another pointer:

```cpp
int value = 5;
int* ptr = &value;
int** ptr_to_ptr = &ptr;
std::cout << **ptr_to_ptr << '\n';  // 5
```

#### Array pointers and pointers to arrays

An element pointer can traverse an array, but does not carry the array's
length. A pointer-to-array points to the whole array and includes its bound
in the type:

```cpp
int values[3] = {1, 2, 3};
int* element_ptr = values;
int (*whole_array_ptr)[3] = &values;

std::cout << *(element_ptr + 1) << '\n'; // 2
std::cout << (*whole_array_ptr)[1] << '\n'; // 2
```

#### Function pointers

A function pointer can store the address of a compatible function:

```cpp
int add(int a, int b) {
    return a + b;
}

int (*operation)(int, int) = &add;
int result = operation(2, 3);  // 5
```

#### Pointers to members and the `this` pointer

A pointer-to-member identifies a data member or member function of a class
and is used together with an object of that class. It is not an ordinary
object pointer:

```cpp
struct Point {
    int x;
};

int Point::* x_member = &Point::x;
Point point{4};
point.*x_member = 7;
```

Inside a non-static member function, `this` points to the object on which the
function was called. It is not available in static member functions:

```cpp
struct Counter {
    int value = 0;
    void increment() {
        ++this->value;
    }
};
```

#### Smart pointers (C++)

Smart pointers from `<memory>` manage ownership and release their resources
automatically when appropriate:

```cpp
#include <memory>
#include <utility>

auto unique_value = std::make_unique<int>(25);
auto transferred_value = std::move(unique_value); // Transfers exclusive ownership

auto shared_value = std::make_shared<int>(100);
auto shared_copy = shared_value; // Shares ownership
std::weak_ptr<int> observer = shared_value; // Observes without owning

if (auto locked_value = observer.lock()) {
    std::cout << *locked_value << '\n';
}
```

`std::unique_ptr` cannot be copied, but can be moved. `std::shared_ptr`
releases its object when its last owning pointer is destroyed.
`std::weak_ptr` does not extend the object's lifetime; call `lock()` to obtain
a temporary `std::shared_ptr` before accessing the object. Weak pointers can
help break ownership cycles between shared pointers.

Raw pointers remain useful as non-owning references, but a raw pointer alone
does not express ownership. Prefer smart pointers when a pointer must manage
an object's lifetime.

---

## Memory Management

**Stack vs Heap:**

- Stack: Automatic, fast, limited size
- Heap: Manual allocation, slower, larger

### Dynamic Memory Allocation

```cpp
// Single variables
int* ptr = new int;        // Allocate int
*ptr = 42;
delete ptr;                // Deallocate

// Arrays
int n = 10;
int* arr = new int[n];     // Allocate; elements are uninitialized
int* zeroed = new int[n]{}; // Allocate and initialize all elements to zero
delete[] arr;              // Deallocate with delete[]
delete[] zeroed;

// Avoid memory leaks!
```

- Local variables are on stack
- `new` allocates on heap, `delete` frees
- Always pair `new[]` with `delete[]` (and `new` with `delete`)
- Memory leaks occur when forgetting delete

- Use smart pointers when possible
- Check for null pointers
- Avoid memory leaks

---

## Structures, Unions, and Enums

These are user-defined types. A `struct` groups related fields, a `union`
provides storage for one active member at a time, and an `enum` names a set of
related values.

### Structures (`struct`)

A structure groups data members under one type. In C++, a `struct` can also
have member functions, constructors, and base classes, just like a `class`.
The default access for members and base classes is `public` in a `struct`;
for a `class`, it is `private`.

```cpp
#include <iostream>
#include <string>

struct Student {
    std::string name;
    int roll_number;
    double gpa;

    Student(std::string student_name, int roll, double grade)
        : name(student_name), roll_number(roll), gpa(grade) {}

    void display() const {
        std::cout << name << ", roll " << roll_number
                  << ", GPA " << gpa << '\n';
    }
};

int main() {
    Student student{"Alice", 101, 3.9};
    student.display();
}
```

An aggregate `struct` without user-declared constructors can be initialized
with braces. C++20 also supports designated initializers for aggregates; the
designators must follow the member declaration order:

```cpp
struct Color {
    int red;
    int green;
    int blue;
};

Color color{255, 128, 0};  // Aggregate initialization
// C++20:
Color other{.red = 0, .green = 128, .blue = 255};
```

Members have their own storage, but the object's size can include padding for
alignment. It is not necessarily just the sum of the member sizes.

### Unions (`union`)

Union members share storage. A union's size is sufficient for its largest
member, with any padding required by alignment. A union can store a value in
one member at a time; the program must track which member is active.

```cpp
union Number {
    int integer;
    float real;
};

int main() {
    Number number;
    number.integer = 42;
    std::cout << number.integer << '\n';  // Read the active member

    number.real = 3.14f;  // The active member is now real
    std::cout << number.real << '\n';
}
```

Do not read an inactive member as if it held a value of that member's type.
Unions with non-trivial member types require careful lifetime management.
For most type-safe alternatives, prefer `std::variant` (C++17), which tracks
the active type:

```cpp
#include <iostream>
#include <variant>

std::variant<int, float> value = 42;
int main() {
    value = 3.14f;
    std::cout << std::get<float>(value) << '\n';
}
```

### Enumerations (`enum`)

An enumeration defines a set of named values.

An `unscoped enum's` enumerators are visible in the surrounding scope and can
implicitly convert to an integer type:

```cpp
enum Color { red, green, blue };
int main() {
    Color selected = green;
    int code = selected;
}
```

A `scoped enum` (`enum class`) keeps its enumerators inside the enum's scope and
does not implicitly convert to an integer. It is generally the safer default:

```cpp
enum class TrafficLight : char {
    red = 'R',
    yellow = 'Y',
    green = 'G'
};

int main() {
    TrafficLight signal = TrafficLight::red;
    if (signal == TrafficLight::red) {
        std::cout << "Stop\n";
    }
    char code = static_cast<char>(signal);  // Explicit conversion
}
```

The underlying type may be specified after `:`; otherwise, a scoped enum uses
`int` by default. An unscoped enum can also specify an underlying type.

| Feature            | `struct`                                                | `union`                                   | `enum class`                                   |
| ------------------ | ------------------------------------------------------- | ----------------------------------------- | ---------------------------------------------- |
| Purpose            | Group related members                                   | Share storage among alternative members   | Name a fixed set of values                     |
| Storage            | Each member has its own storage (with possible padding) | Members overlap in storage                | Stores an enumerator using its underlying type |
| Access             | Members use `.` or `->`                                 | Access the active member with `.` or `->` | Use `EnumName::value`                          |
| Typical modern use | Data records and small types                            | Low-level or specialized representation   | Type-safe states and options                   |

---

## Object-Oriented Programming

### Classes and Objects

**Class:** Blueprint for objects

**Object:** Instance of a class

- Class members: attributes (variables) and methods (functions)
- Methods can be defined inside or outside class but decalartion should be inside class.
- Outside definition uses `::` operator
- Objects are created from classes

### Class Definition

```cpp
class Rectangle {
private:
    double width, height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Destructor
    ~Rectangle() {}

    // Member function
    double area() {
        return width * height;
    }

    // Static member
    static int count;
};

// Static member definition
int Rectangle::count = 0;
```

### Object Creation

```cpp
Rectangle rect(10, 5);     // Stack object
Rectangle* ptr = new Rectangle(10, 5);  // Heap object
delete ptr;
```

### Constructors

Constructors are special member functions called when an object is initialized.
They have the class name, no return type, and can be overloaded with different
parameter lists. Use a member-initializer list to initialize members:

C does not have C++ classes or constructor/destructor special member functions;
initialization and cleanup in C are handled with ordinary functions.

```cpp
#include <iostream>
#include <string>
#include <utility>

class Box {
public:
    Box() : width(1), height(1), color("White") {} // Default constructor

    Box(int w, int h, std::string c = "White") // Parameterized constructor
        : width(w), height(h), color(c) {}

    Box(const Box&) = default;       // Copy constructor
    Box(Box&&) noexcept = default;   // Move constructor

    void display() const {
        std::cout << width << " x " << height << ", " << color << '\n';
    }

private:
    int width;
    int height;
    std::string color;
};

int main() {
    Box default_box;                // Default constructor
    Box custom_box{10, 20, "Red"};  // Parameterized constructor
    Box copied_box = custom_box;    // Copy constructor
    Box moved_box = std::move(copied_box); // Move constructor
    moved_box.display();
}
```

The example uses `std::move`, so include `<utility>` in a complete program.

Common constructor forms are:

- **Default constructor:** Can be called with no arguments. The compiler
  implicitly declares one only when the class has no user-declared
  constructors. Declaring a parameterized constructor prevents that implicit
  default constructor; define one explicitly if it is still needed.
- **Parameterized constructor:** Accepts values to initialize the object.
- **Copy constructor:** Initializes an object from another object of the same
  type, usually taking `const ClassName&`.
- **Move constructor (C++11+):** Can transfer resources from an rvalue, usually
  taking `ClassName&&`. A moved-from object remains valid but its value is
  generally unspecified.

#### Constructor overloading

Constructor overloading means providing multiple constructors with different
parameter lists. The compiler selects one based on the arguments used to
initialize the object:

```cpp
#include <iostream>
#include <string>

class Box {
public:
    Box() : width(1), height(1), color("White") {}

    Box(int w, int h) : width(w), height(h), color("White") {}

    Box(int w, int h, std::string c)
        : width(w), height(h), color(c) {}

    void display() const {
        std::cout << width << " x " << height << ", " << color << '\n';
    }

private:
    int width;
    int height;
    std::string color;
};

int main() {
    Box default_box;               // Calls Box()
    Box plain_box{10, 20};         // Calls Box(int, int)
    Box colored_box{5, 8, "Red"};  // Calls Box(int, int, std::string)

    default_box.display();
    plain_box.display();
    colored_box.display();
}
```

Constructors are distinguished by parameter types and count, not by parameter
names or return type. Avoid overloads whose default arguments make the same
call ambiguous.

### Copy Constructor

The copy constructor creates a new object from an existing one:
`ClassName(const ClassName& other)`. The compiler-generated copy constructor
copies each member. This is usually correct for value members such as
`std::string` and `std::vector`. A class that owns a raw resource may need
custom copy behavior; prefer RAII members such as standard containers and smart
pointers to avoid manually managing that resource.

**Key points to remember:**

- Used when initializing one object from another, and can also be used when passing an object by value
- A memberwise copy copies pointer values, not the objects they point to
- If a class needs a custom destructor, copy constructor, or copy assignment operator, consider the Rule of Three; with move operations, consider the Rule of Five. Prefer the Rule of Zero when RAII members can manage resources.

### `this` Pointer

`this` is an implicit pointer available in a non-static member function. It refers to the object on which the function was called. In a `const` member function, the pointed-to object is treated as const. `this` is not available in static member functions because they are not called on a particular object.

• It's a Pointer: The type of this inside a class Player is Player\* (a pointer to a Player object).
• Read-Only: You cannot modify the value of this itself (e.g., this = nullptr; is illegal).
• Non-Static Only: `It only exists inside ordinary member functions. It is not available inside static member functions because static functions belong to the class as a whole, not to a specific object instance.`

#### Distinguishing members from parameters

A parameter can hide a member with the same name. Use `this->member` to refer explicitly to the member:

```cpp
class Employee {
private:
    int id;

public:
    void set_id(int id) {
        this->id = id;
    }
};
```

#### Method chaining

Returning `*this` by reference allows multiple calls to operate on the same object:

```cpp
#include <iostream>

class Calculator {
public:
    Calculator& add(int number) {
        value += number;
        return *this;
    }

    void print() const {
        std::cout << "Result: " << value << '\n';
    }

private:
    int value = 0;
};

int main() {
    Calculator calculator;
    calculator.add(5).add(10).add(2);
    calculator.print();  // Result: 17
}
```

#### Passing the current object

Use `this` to pass the current object's address to a function that accepts a pointer. Use `*this` when the function expects an object or reference:

```cpp
class Box;
void process_box(Box* box);

class Box {
public:
    void send_to_processor() {
        process_box(this);
    }
};
```

In a non-static member function of class `T`, the type of `this` is a `T* const` expression: the pointer itself cannot be reassigned. In a `const` member function, it is `const T* const`. These are not declarations you write for a local variable; they describe the type and constness of the implicit `this` expression.

### Destructors

A destructor is a special member function named `~ClassName()`. It has no return type, takes no parameters, and cannot be overloaded. It runs when an object's lifetime ends—for example, when a local object leaves scope or when a heap object is deleted.

```cpp
#include <iostream>
#include <string>
#include <utility>

class Tracker {
public:
    explicit Tracker(std::string object_name) : name(std::move(object_name)) {
        std::cout << "Constructed " << name << '\n';
    }

    ~Tracker() {
        std::cout << "Destroyed " << name << '\n';
    }

private:
    std::string name;
};

int main() {
    {
        Tracker local{"inner scope"};
    } // Destroyed here

    Tracker outer{"main scope"};
} // Destroyed as main exits
```

Include `<utility>` for `std::move`. In production code, destructors usually do not need to manually close files or free memory when RAII types such as `std::ofstream`, `std::vector`, and smart pointers own those resources. Destructors in polymorphic base classes should generally be `virtual` when bjects may be deleted through a base-class pointer.

### Access Specifiers

1. **public:** Accessible everywhere
2. **private:** Accessible only within class
3. **protected:** Accessible in class and derived classes
4. **Default:** private for classes, public for structs

### Static Members

Static data members belong to the class rather than to an individual object,
so the class has one shared member. They have static storage duration; their
initialization timing depends on the initializer and program startup rules,
not necessarily the moment the first object is constructed.

Before C++17, a static data member generally needs an out-of-class definition.
Since C++17, an `inline static` member can be initialized in the class:

```cpp
#include <iostream>

class Counter {
public:
    static int count;                  // Declaration
    static int get_count() { return count; }
};

int Counter::count = 0;                // Definition (before C++17)

class ModernCounter {
public:
    inline static int count = 0;       // C++17
};

int main() {
    ++Counter::count;
    ++Counter::count;
    std::cout << Counter::get_count() << '\n'; // 2

    ++ModernCounter::count;
    std::cout << ModernCounter::count << '\n'; // 1
}
```

Prefer accessing static members with `ClassName::member`. They can also be accessed through an object, but that may misleadingly suggest they belong to that particular object.

Static member functions can be called without an object and do not have a `this` pointer. They can access static members directly. They cannot access a non-static member without an object, but can access one through an explicit
object or reference:

```cpp
class Example {
public:
    int value = 0;
    static void reset(Example& object) {
        object.value = 0;  // Explicit object required
    }
};
```

A `static` local variable inside an ordinary function is different from a static class member: it is local in scope but retains its value between calls. Since C++11, its initialization is thread-safe:

```cpp
int next_id() {
    static int id = 0;  // Initialized once; retains its value
    return ++id;
}
```

Static member functions also cannot be `virtual` or `const`-qualified; those features apply to functions called on a particular object.

### Friend Functions/Classes

`friend` grants a specified non-member function or another class access to a class's private and protected members. Use it selectively; friendship does not make the friend a member of the granting class.

#### Friend function

A friend function can be declared in any access section. Its definition is written as a normal non-member function, and it is called like one—not through an object:

```cpp
#include <iostream>

class Distance {
private:
    int meters = 0;

public:
    friend void add_five(Distance& distance);

    void display() const {
        std::cout << distance_label() << meters << " m\n";
    }

private:
    const char* distance_label() const {
        return "Distance: ";
    }
};

void add_five(Distance& distance) {
    distance.meters += 5;  // Friend can access private members
}

int main() {
    Distance distance;
    add_five(distance);
    distance.display();
}
```

`add_five(distance)` is valid; `distance.add_five()` is not, because `add_five` is not a member function.

#### Friend class

Declaring a class as a friend grants all its member functions access to the ugranting class's private and protected members:

```cpp
#include <iostream>
#include <string>

class Database {
private:
    std::string label = "Example database";
    friend class Admin;
};

class Admin {
public:
    void print_label(const Database& database) const {
        std::cout << database.label << '\n';
    }
};

int main() {
    Database database;
    Admin admin;
    admin.print_label(database);
}
```

Friendship is not mutual, inherited, or transitive. If `A` is a friend of `B`, that does not make `B` a friend of `A`, grant `A` access to a derived class's private members, or give `A` access to classes that `B` is friends with. Friendship must be granted explicitly by each class.

Use `friend` only when a function or class genuinely needs access to the implementation; prefer a public member function when it expresses the intended interface more clearly.

### 4 Pillars of OOP

Object-oriented programming is often explained through four related ideas:encapsulation, abstraction, inheritance, and polymorphism.

1. **Abstraction:** Hide complexity, show essentials
2. **Encapsulation:** Bundle data and methods, control access
3. **Inheritance:** Derive new classes from existing ones
4. **Polymorphism:** Objects behave differently based on context

- Abstraction: focus on what, not how, Minimizing Complexity -> `Pure virtual functions`, `Abstract classes`.
- Encapsulation: safty and data security -> `private`, `public`, `protected` access specifiers.
- Inheritance: code reuse and hierarchy -> `class Child` : public Parent syntax blocks.
- Polymorphism: same interface, different behavior -> `Function overloading`, `virtual function overriding`.

#### Encapsulation

Encapsulation groups data with the operations that work on it and controls access to the object's state. Keep invariants inside the class; expose only operations that make sense instead of automatically adding a getter and setter for every field.

```cpp
class BankAccount {
public:
    bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }

    double get_balance() const {
        return balance;
    }

private:
    double balance = 0;
};
```

#### Abstraction

Abstraction exposes a useful interface while hiding implementation details. It can be provided by ordinary classes and functions; abstract classes with pure virtual functions are one way to define an interface:

```cpp
class Appliance {
public:
    virtual void turn_on() = 0;
    virtual ~Appliance() = default;
};

class Washer : public Appliance {
public:
    void turn_on() override {
        // Implementation details are hidden behind the interface.
    }
};
```

---

## Inheritance

Inheritance creates a derived class from a base class. It can share and specialize behavior, but model a genuine “is-a” relationship rather than using inheritance only to reuse code:

**What it is:** Creating new classes from existing classes.

**Syntax:** `class Derived : public Base { ... };`

- Derived class inherits members from base class
- Access specifiers control inheritance visibility
- Base class constructor called first
- Derived class can override base methods

### Basic Inheritance

```cpp
class Vehicle {
public:
    virtual void move() {}
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void move() override {}
};
```

```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};

Dog dog;
dog.eat();   // Inherited
dog.bark();  // Own method
```

### Types of Inheritance

**What it is:** Different ways classes can inherit from one another to build relationships.

#### Single Inheritance

One derived class inherits from one base class.

```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};
```

**When to use:** Simple parent-child relationships.

#### Multilevel Inheritance

A class inherits from a derived class, creating a chain.

```cpp
class Animal { public: void eat() {} };
class Mammal : public Animal { public: void breathe() {} };
class Dog : public Mammal { public: void bark() {} };
```

**When to use:** Use when behavior is added in layers.

#### Hierarchical Inheritance

Multiple derived classes inherit from the same base class.

```cpp
class Animal { public: void eat() {} };
class Dog : public Animal { public: void bark() {} };
class Cat : public Animal { public: void meow() {} };
```

**When to use:** One base class shared by many child classes.

#### Multiple Inheritance

A derived class inherits from more than one base class.

```cpp
class A { public: void funcA() {} };
class B { public: void funcB() {} };
class C : public A, public B {};
```

**When to use:** Combine independent behavior from several classes.

#### Hybrid Inheritance

A mix of two or more types of inheritance, such as multiple and multilevel.

```cpp
class Animal { public: void eat() {} };
class Pet : public Animal { public: void play() {} };
class GuideDog : public Pet, public Service { public: void guide() {} };
```

**When to use:** Use with care; structure can become complex.

#### Access Control with Inheritance

Inheritance also controls member visibility:

- `public` inheritance: public and protected base members keep their access levels in derived class.
- `protected` inheritance: public and protected base members become protected in derived class.
- `private` inheritance: public and protected base members become private in derived class.

**Key points to remember:**

- Use `public` inheritance for an "is-a" relationship.
- Use `protected` or `private` inheritance only when you want to hide base interface.
- `private` inheritance is more like implementation reuse than true inheritance.

### Virtual Inheritance (Diamond Problem)

Imagine `Parent1` and `Parent2` both inherit from `Grandparent`. If `Child` inherits from both parents without virtual inheritance, it gets two `Grandparent` parts—one through each parent. So `child.data` is ambiguous: the compiler cannot tell which copy you mean.

```cpp
#include <iostream>

struct Grandparent {
    int data = 0;
    Grandparent() {
        std::cout << "Grandparent\n";
    }
};

struct Parent1 : virtual public Grandparent {
    Parent1() {
        std::cout << "Parent1\n";
    }
};

struct Parent2 : virtual public Grandparent {
    Parent2() {
        std::cout << "Parent2\n";
    }
};

struct Child : public Parent1, public Parent2 {
    Child() {
        std::cout << "Child\n";
    }
};

int main() {
    Child child;
    child.data = 42;  // One shared Grandparent subobject
    std::cout << child.data << '\n';
}
```

With virtual inheritance, `Child` contains one shared `Grandparent` base subobject, so `child.data` is unambiguous. The virtual inheritance is declared on both intermediate classes; it is not declared on `Child`.

Construction order is the virtual base first, then direct non-virtual bases in the order they appear in the base list, then members, then the derived class body. The most-derived class is responsible for initializing virtual bases. If `Grandparent` had a parameterized constructor, `Child` would initialize it in its member-initializer list. An intermediate class's virtual-base initializer is used only when that intermediate class itself is the most-derived class.

The C++ language guarantees the shared virtual base subobject, but does not prescribe a specific object-memory layout or require a particular hidden pointer implementation. Virtual inheritance is useful for shared-base diamonds, but it can add layout and access complexity, so use it when that shared-base relationship is intended.

---

## Polymorphism

Polymorphism lets the same interface work with different types. Compile-time polymorphism includes `function and operator overloading`. Runtime polymorphism uses `virtual functions and overriding`:

```cpp
#include <iostream>

class Animal {
public:
    virtual void make_sound() const {
        std::cout << "Some sound\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void make_sound() const override {
        std::cout << "Woof!\n";
    }
};

void play_sound(const Animal& animal) {
    animal.make_sound();
}
```

For runtime polymorphism, call through a base pointer or reference; virtual dispatch then invokes the override for the actual object type.

| Pillar        | Main idea                                           | Common C++ mechanisms                        |
| ------------- | --------------------------------------------------- | -------------------------------------------- |
| Encapsulation | Protect object state and its invariants             | Classes, access specifiers, member functions |
| Abstraction   | Expose an interface and hide implementation details | Functions, classes, abstract base classes    |
| Inheritance   | Derive and specialize a related type                | Base and derived classes                     |
| Polymorphism  | Use one interface with different behavior           | Overloading, virtual functions, overriding   |

### Compile-time Polymorphism

**Compile-time:** Function overloading, operator overloading

#### Function Overloading

Function overloading allows you to define multiple functions with the exact same name within the same scope, provided they have different parameter lists (signatures)

```cpp
#include <iostream>

class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

int main() {
    Calculator calculator;
    std::cout << calculator.add(2, 3) << '\n';
    std::cout << calculator.add(2.5, 3.5) << '\n';
}
```

#### Operator Overloading

Operator overloading defines how an existing operator works with a user-defined type. It cannot create a new operator symbol or change the
operator's precedence, associativity, or number of operands.

```cpp
#include <iostream>

class Complex {
private:
    double real, imag;

public:
    Complex(double real, double imag) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    }

    void display() const {
        std::cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex first{3, 4};
    Complex second{1, 2};
    Complex sum = first + second;
    sum.display();
}
```

Some operators cannot be overloaded, including `::`, `.`, `.*`, and `?:`.
`sizeof` is an operator, not a function; its behavior cannot be customized by
overloading. Overloads should preserve familiar behavior so expressions remain
clear.

### Runtime Polymorphism

Runtime polymorphism lets a base-class reference or pointer call an overridden function on the actual derived object. The function must be declared `virtual` in the base class; mark the derived implementation `override` so the compiler checks that it really overrides a base function.

#### Virtual Functions

```cpp
#include <iostream>

class Animal {
public:
    virtual void make_sound() const {
        std::cout << "Some generic animal sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void make_sound() const override {
        std::cout << "Woof!\n";
    }
};

void play_sound(const Animal& animal) {
    animal.make_sound();  // Calls the override for the actual object
}

int main() {
    Dog dog;
    play_sound(dog);  // Prints "Woof!"
}
```

Use a virtual destructor in a polymorphic base class when objects might be deleted through a base pointer. An abstract base class typically has a protected or public virtual destructor.

#### Pure virtual functions and abstract classes

A pure virtual function is declared with `= 0`.`A class with at least one pure virtual function is abstract`and cannot be instantiated directly. Derived classes must override all inherited pure virtual functions to become instantiable; otherwise, they remain abstract.

Abstract classes can still have data members, constructors, and implemented member functions:

```cpp
#include <iostream>

class Shape {
public:
    virtual double area() const = 0;

    void print_info() const {
        std::cout << "Area: " << area() << '\n';
    }

    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

int main() {
    Circle circle{5.0};
    const Shape& shape = circle;
    shape.print_info();
}
```

| Feature                           | Virtual function    | Pure virtual function                                                 |
| --------------------------------- | ------------------- | --------------------------------------------------------------------- |
| Declaration                       | `virtual void f();` | `virtual void f() = 0;`                                               |
| Base implementation               | May provide one     | Usually defines an interface; a separate definition is also permitted |
| Must a derived class override it? | No                  | Yes, to become concrete                                               |
| Makes its class abstract?         | No, not by itself   | Yes                                                                   |

Pure virtual functions provide an interface requirement; they do not mean a derived class can override only one function and still be instantiated when other inherited pure virtual functions remain unimplemented.

---

## Templates

In C++, templates are a powerful feature that allows you to write generic, reusable code. They act as a blueprint or formula for creating classes or functions without locking them into a specific data type [•].

Instead of writing separate duplicate functions for `int`, `float`, and `double`, you write a single template function, and the compiler automatically generates the required variations behind the scenes [•]. This is a core component of generic programming [•].

### Function Templates

**What it is:** Generic functions that work with any data type.

**Syntax:**

```cpp
template <typename T>
T function_name(T param) {
    // code
}
```

- T acts as placeholder data type
- Compiler generates code for each used type
- Type safety maintained
- Avoid code duplication
- Can have multiple template parameters

```cpp
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
cout << maximum(5, 10) << endl;        // 10
cout << maximum(3.14, 2.71) << endl;   // 3.14
```

### Class Templates

**What it is:** Generic classes that work with any data type. A class template allows a whole class layout to use generic types for its data members and member function signatures

**Syntax:**

```cpp
template <typename T>
class ClassName {
    // use T as type
};
```

- Instantiate with specific types: `ClassName<int> obj;`
- Template parameters can be types or values
- Useful for containers, algorithms
- Standard library heavily uses templates

```cpp
template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(T item) { elements.push_back(item); }
    T pop() { T item = elements.back(); elements.pop_back(); return item; }
};

// Usage
Stack<int> intStack;
intStack.push(5);
```

It is critical to know that template blocks do not take up any space in the compiled binary by themselves.
When the compiler encounters `findMax<int>(10, 20)`, it goes through a phase called Template Instantiation [•]. It creates an actual copy of the function code replacing T with int [•]. If a template is never called or matched in your code, no actual code is generated.

### Template Specialization

**What it is:** Special implementation for specific types.

- General template for most types
- Specialized version for specific types like bool
- Compiler chooses most specific match
- Useful when general implementation doesn't work for some types

```cpp
template <typename T>
class Printer {
public:
    void print(T value) { cout << value << endl; }
};

// Specialization for bool
template <>
class Printer<bool> {
public:
    void print(bool value) { cout << (value ? "true" : "false") << endl; }
};
```

---

## Exception Handling

**What it is:** Mechanism for handling runtime errors.

**Syntax:**

```cpp
try {
    // risky code
} catch (exception_type& e) {
    // handle error
}
```

- throw exceptions with `throw`
- Catch by reference to avoid slicing
- Multiple catch blocks for different types
- catch(...) catches all exceptions

### Standard Exception Hierarchy

Understanding the exception hierarchy helps you catch the right exception type.

```
std::exception                          ← base of everything
├── std::logic_error                    ← programmer mistakes (detectable before runtime)
│   ├── std::invalid_argument           ← invalid function parameter
│   ├── std::domain_error               ← input outside valid domain
│   ├── std::length_error               ← length exceeds max possible
│   └── std::out_of_range               ← subscript out of range
│
├── std::runtime_error                  ← problems at runtime (can't predict ahead)
│   ├── std::range_error                ← result out of range
│   ├── std::overflow_error             ← arithmetic overflow
│   └── std::underflow_error            ← arithmetic underflow
│
├── std::bad_alloc                      ← thrown by new when memory allocation fails
├── std::bad_cast                       ← thrown by dynamic_cast with references
└── std::bad_typeid                     ← thrown by typeid operator
```

**Key points to remember:**

- `std::logic_error`: Programmer bugs that could be detected before running
- `std::runtime_error`: Conditions that can't be predicted (file not found, invalid input)
- Catch more specific exceptions before general ones
- Always catch `std::exception` as the final fallback

**Example:**

```cpp
try {
    // your code
} catch (const std::out_of_range& e) {
    cout << "Out of range: " << e.what() << endl;
} catch (const std::logic_error& e) {
    cout << "Logic error: " << e.what() << endl;
} catch (const std::runtime_error& e) {
    cout << "Runtime error: " << e.what() << endl;
} catch (const std::exception& e) {
    cout << "General exception: " << e.what() << endl;
}
```

### Basic Exception Handling

```cpp
try {
    // Code that might throw exception
    if (denominator == 0) {
        throw runtime_error("Division by zero!");
    }
} catch (const runtime_error& e) {
    cout << "Error: " << e.what() << endl;
} catch (...) {
    cout << "Unknown error occurred" << endl;
}
```

### Custom Exceptions

```cpp
class MyException : public exception {
public:
    const char* what() const throw() {
        return "My custom exception";
    }
};
```

### RAII (Resource Acquisition Is Initialization)

```cpp
class FileHandler {
private:
    FILE* file;
public:
    FileHandler(const char* filename) {
        file = fopen(filename, "r");
        if (!file) throw runtime_error("Cannot open file");
    }
    ~FileHandler() {
        if (file) fclose(file);
    }
    // Use file...
};
```

---

## File I/O

### File Streams

1. **ofstream:** Write to files
2. **ifstream:** Read from files
3. **fstream:** Read and write files

- Include `<fstream>` header
- Check if file opened successfully
- Close files after use
- Different modes: in, out, app, binary, trunc

### File Operations

**Writing:**

```cpp
ofstream file("output.txt");
file << "Hello World" << endl;
file.close();
```

**Reading:**

```cpp
ifstream file("input.txt");
string line;
while (getline(file, line)) {
    cout << line << endl;
}
file.close();
```

- Files can be text or binary
- Error handling: check `file.is_open()`
- Use appropriate stream for operation
- Close files to flush buffers

```cpp
#include <fstream>

ofstream outFile("output.txt");
outFile << "Hello World!" << endl;
outFile.close();

ifstream inFile("input.txt");
string line;
while (getline(inFile, line)) {
    cout << line << endl;
}
inFile.close();

// Binary files
ofstream binFile("data.bin", ios::binary);
int data = 42;
binFile.write(reinterpret_cast<char*>(&data), sizeof(data));
binFile.close();
```

### File Modes

- `ios::in`: Read
- `ios::out`: Write (default for ofstream)
- `ios::app`: Append
- `ios::binary`: Binary mode
- `ios::trunc`: Truncate file

---

## Standard Template Library (STL)

The STL is a set of template-based components designed to be efficient, flexible, and reusable. It gives you ready-made data structures, generic algorithms, and iterator abstractions so you can focus on solving problems instead of reimplementing container logic.

### STL Components

- **Containers:** Store objects and data.
- **Algorithms:** Perform operations on containers or ranges.
- **Iterators:** Connect containers with algorithms like pointers.

### Why use STL?

- Fast and reliable implementations
- Type-safe through templates
- Easy to use once you know the patterns
- Saves time compared to writing your own data structures

### Containers

Containers are the data structures used to store objects and data. Each container is a class template that provides methods for insertion, removal, access, and traversal. Every STL container is defined inside its own header and is designed to work with iterators and algorithms.

Containers can be classified into four types:

- **Sequence Containers:** Store elements in a linear order. Use them when order matters and you need sequential access.
  - `vector`: dynamic array, best for random access and append operations
  - `deque`: double-ended queue, efficient push/pop at both ends
  - `list`: doubly linked list, efficient insertion/removal from anywhere
  - `forward_list`: singly linked list, lower memory overhead for forward-only traversal
  - `array`: fixed-size array with stack allocation and static size
- **Container Adaptors:** Provide a restricted interface by using other sequence containers internally.
  - `stack`: LIFO behavior, use when only top access is needed
  - `queue`: FIFO behavior, use for breadth-first order
  - `priority_queue`: always expose the largest element first
- **Associative Containers:** Store elements in sorted order and allow fast lookup by key.
  - `set`: unique sorted values
  - `multiset`: sorted values with duplicates allowed
  - `map`: sorted key-value pairs with unique keys
  - `multimap`: sorted key-value pairs with duplicate keys allowed
- **Unordered Associative Containers:** Store elements in hash buckets for average constant-time lookup.
  - `unordered_set`: unique values with hash-based lookup
  - `unordered_multiset`: duplicate values allowed
  - `unordered_map`: key-value pairs with hash-based lookup
  - `unordered_multimap`: duplicate hashed keys allowed

Using STL containers means you do not need to manually implement memory management and traversal for common data structures. They are tested, optimized, and work consistently across compilers.

#### Vector (Dynamic Array)

`vector` is the most common sequence container. It stores elements contiguously, so random access is fast and it works well with C-style arrays.

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n = 5;
    vector<int> sized(n);           // 5 elements, initialized to 0
    vector<int> filled(n, 10);      // 5 elements, each equal to 10
    vector<int> initialized = {1, 2, 3};
    vector<int> resizable;          // Empty; can grow or shrink

    vector<int> vec = {1, 2, 3};
    vec.push_back(4);                 // Add element
    vec.insert(vec.begin() + 1, 10); // Insert at position 1
    vec.pop_back();                   // Remove last element

    for (int value : vec) {
        cout << value << " ";
    }
    cout << "\nSize: " << vec.size() << endl; //size
}
```

#### Array (Fixed-Size Array)

`array` is a fixed-size container. Its size is part of its type, and it provides
container operations such as `.size()`.

```cpp
#include <array>
#include <iostream>

std::array<int, 5> a;                 // Fixed size; elements are default-initialized
std::array<int, 5> zeroed{};          // All elements are zero
std::array<int, 3> initialized = {1, 2, 3};

std::cout << initialized.size();      // 3
```

#### List (Doubly Linked List)

`list` stores elements as a doubly linked chain. It is useful when you need to insert or remove items frequently in the middle of the container.

```cpp
#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> lst = {1, 2, 3};
    lst.push_front(0);       // Add to front
    lst.push_back(4);        // Add to back
    lst.pop_front();         // Remove from front

    for (int value : lst) {
        cout << value << " ";
    }
    cout << endl;
}
```

#### Map (Associative Array)

`map` stores sorted key-value pairs. It is ideal when you need lookups by key and want keys kept in order.

```cpp
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores.insert({"Carol", 92});

    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
```

#### Set (Unique Elements)

`set` stores unique sorted values and is useful when duplicates are not allowed.

```cpp
#include <set>
#include <iostream>

using namespace std;

int main() {
    set<int> numbers = {1, 2, 3, 2};  // Duplicates removed
    numbers.insert(4);
    numbers.erase(2);

    for (int value : numbers) {
        cout << value << " ";
    }
    cout << endl;
}
```

### Algorithms

STL algorithms offer a wide range of functions to perform common operations on data, mainly containers. They implement efficient versions of tasks such as sorting, searching, modifying, and manipulating ranges.

Most algorithms are defined in `<algorithm>` and `<numeric>`, while some specialized utilities appear in headers like `<memory>`, `<functional>`, and `<iterator>`.

Some commonly used algorithms:

- `sort`: Arranges elements in ascending order (default)
- `binary_search`: Checks whether a value exists in a sorted range
- `find`: Searches for the first occurrence of a given value
- `count`: Counts how many times a value appears in a range
- `reverse`: Reverses the order of elements in a range
- `accumulate`: Computes the sum of all elements in a range
- `unique`: Removes consecutive duplicate elements
- `lower_bound`: Returns iterator to first element ≥ value in a sorted range
- `upper_bound`: Returns iterator to first element > value in a sorted range
- `replace`: Replaces all occurrences of an old value with a new value in the given range

```cpp
#include <algorithm>

vector<int> vec = {3, 1, 4, 1, 5};
sort(vec.begin(), vec.end());           // Sort
reverse(vec.begin(), vec.end());        // Reverse
int max_val = *max_element(vec.begin(), vec.end());
bool found = binary_search(vec.begin(), vec.end(), 4);
```

### Iterators

Iterators are pointer-like objects that point to elements inside STL containers. They connect containers with algorithms and let generic code work on many container types.

Iterators are defined in headers like `<iterator>` and usually provided by containers through methods such as `begin()`, `end()`, `rbegin()`, and `rend()`.

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << endl;
}

// Range-based for loop (C++11+)
for (int num : vec) {
    cout << num << endl;
}
```

- Iterators can be input, output, forward, bidirectional, or random-access
- Use iterator categories to choose the correct algorithm support
- `auto` is helpful for iterator type deduction

---

## Advanced Concepts

### Namespaces

**What it is:** Containers for identifiers to avoid name conflicts.

- Group related code
- Prevent naming collisions
- `std` is the standard namespace
- Access with `::` operator
- Can be nested

### Smart Pointers (C++11+)

**What it is:** Automatic memory management.

**Types:**

- `unique_ptr`: Exclusive ownership
- `shared_ptr`: Shared ownership
- `weak_ptr`: Breaks circular references

- Prefer smart pointers over raw pointers
- Automatic cleanup when out of scope
- `make_unique` and `make_shared` for creation
- No manual delete needed

```cpp
#include <memory>

// Unique pointer (exclusive ownership)
unique_ptr<int> uptr = make_unique<int>(42);

// Shared pointer (shared ownership)
shared_ptr<int> sptr1 = make_shared<int>(42);
shared_ptr<int> sptr2 = sptr1;  // Reference count increases

// Weak pointer (breaks circular references)
weak_ptr<int> wptr = sptr1;
```

### Move Semantics (C++11+)

**What it is:** Efficient transfer of resources.

- Move constructor: `Class(Class&& other)`
- Move assignment: `Class& operator=(Class&& other)`
- `std::move()` converts to rvalue reference
- Avoid unnecessary copies

```cpp
class String {
private:
    char* data;
    size_t size;
public:
    // Move constructor
    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }

    // Move assignment
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};
```

### Lambda Expressions

**Advanced usage:**

```cpp
auto lambda = [capture](params) mutable -> return_type {
    // body
};
```

- Capture by value `[x]`, reference `[&x]`, or all `[&]`
- `mutable` allows modifying captured values
- Return type can be auto-deduced
- Useful with algorithms

### constexpr (C++11+)

**What it is:** Compile-time computation.

- Functions evaluated at compile time
- Variables known at compile time
- Improves performance
- Restrictions on what can be done

```cpp
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

constexpr int fact5 = factorial(5);  // Computed at compile time
```

### Threading (C++11+)

**What it is:** Concurrent execution.

- Include `<thread>` header
- `std::thread` for creating threads
- `join()` waits for thread completion
- `detach()` allows independent execution
- Synchronization with mutexes

```cpp
#include <thread>

void worker(int id) {
    cout << "Worker " << id << endl;
}

thread t1(worker, 1);
thread t2(worker, 2);
t1.join();  // Wait for thread to finish
t2.join();
```

---
