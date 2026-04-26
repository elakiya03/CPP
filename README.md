## 1. `#include <iostream>`

**Why we use it:** `iostream` stands for "input/output stream". It contains definitions for reading input from the user (using `cin`) and displaying output on the screen (using `cout`). Without this, we cannot use `cout` to print text.
**Example without it:** If you try to use `cout` without `#include <iostream>`, you'll get a compilation error saying `cout` is not defined.

---

## 2. `using namespace std;`

**What it is:** A statement that tells the compiler to use the standard namespace.

**Why we use it:** In C++, `std` is the **standard namespace** where common functions and objects like `cout`, `cin`, `endl`, etc. are defined.

**Without it:** You would need to write `std::cout` instead of just `cout` every time.

---

## 3. `int main()`

**What it is:** The main function - the entry point of your program.
**Why we use it:** Every C++ program must have a `main()` function. This is where your program starts executing. The `int` means this function returns an integer value.
**When it runs:** When you run your program, the operating system looks for and executes `main()` first.

---

## 4. `return 0;`

**What it is:** A return statement that exits the main function.
**Why we use it:** Returns an integer value to the operating system.

**What 0 means:**

- `0` = Program executed successfully (no errors)
- Non-zero (like `1`) = Program encountered an error

**Why it matters:**

- The operating system checks this return value
- Other programs can detect if your program ran successfully
- In shell scripts, you can check if a program succeeded using the exit code

---

## Summary

| Part                   | Purpose                                                       |
| ---------------------- | ------------------------------------------------------------- |
| `#include <iostream>`  | Include input/output library                                  |
| `using namespace std;` | Use standard namespace (allows `cout` instead of `std::cout`) |
| `int main()`           | Entry point of the program                                    |
| `cout << "hello ";`    | Print text to screen                                          |
| `return 0;`            | Return success to operating system                            |

---

### 5. Data type

1. bool - true 1, false 0
2. char
3. int
4. float
5. double
6. string

- `boolalpha` is not a data type. It is an I/O manipulator - a setting that changes how cout displays boolean values. When you use it, you are telling cout: "`From now on, print booleans as true and false instead of 1 and 0`."
- If you want to go back to the default behavior (printing 1 and 0), you can use `noboolalpha`.

---

### ASCII

[a-z] - [97-122]
[A-Z]- [65-90]

### Keywords

1. auto - automatically detects the type of a variable based on the value you assign to it. only works when you assign a value at the same time.

### Operators

1. Arithmetic + - \* / % ++ --
2. Assignment = += -+ \*= /+ %= &= |= ^= >>= <<= //compound operators
3. Comparison == != < > <= >=
4. Logical && || !

### Precedence

1.  () [] -> . (postfix)
2.  ! ~ ++ -- (cast) (unary)
3.  - / % (mult)
4.  - - (add)
5.  << >> (shift)
6.  < <= > >= (relational)
7.  == != (equality)
8.  & (bitwise AND)
9.  ^ (bitwise XOR)
10. | (bitwise OR)
11. && (logical AND)
12. || (logical OR)
13. ?: (ternary)
14. = += -= ... (assignment)

### Reference

A reference variable is an alias for an existing variable. It is created using the & operator.

### Pointer

- When used in declaration (string\* ptr), it creates a `pointer variable`.
- When not used in declaration, it act as a `dereference operator`.

### Memory

- memory is automactically handled by complier

### Function

- Pass array as function parameter
- pass structure to a function
- pass structure by reference to a function - Since the structure is passed by value, the function gets a copy of the structure. This means that the original data is not changed.

## Function Overloading

- `Function overloading` allows multiple functions to have the same name, as long as their parameters are different in type or number.

- Multiple functions can have the same name as long as the number and/or type of parameters are different.

- `Lambda Function` - When you only need the function once and it's short

### Object-orieneted programming

# class and object

- Attributes and methods are basically variables and functions that belongs to the class. These are often referred to as "class members".

- A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.

- Methods can be defined both inside and outside of class but declaration should be inside class

- using the :: operator with the class, is how methods outside a class defined

# constructors

- The constructor has the same name as the class.
- It has no return type (not even void).
- It is usually declared public.
- It is automatically called when an object is created.
- It can take parameters which can be suefull for setting inital values
