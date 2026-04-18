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
