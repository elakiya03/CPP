# C++ Programming Guide: From Basics to Advanced

This comprehensive guide covers C++ concepts with detailed explanations, key points to remember, and practical coding tips. It builds on your existing notes while adding comprehensive coverage.

## Table of Contents

1. [Introduction to C++](#introduction-to-c)
2. [Basic Syntax and Structure](#basic-syntax-and-structure)
3. [Data Types](#data-types)
4. [Operators and Precedence](#operators-and-precedence)
5. [Control Structures](#control-structures)
6. [Type Conversion and Casting](#type-conversion-and-casting)
7. [Functions](#functions)
8. [Arrays and Strings](#arrays-and-strings)
9. [References and Pointers](#references-and-pointers)
10. [Memory Management](#memory-management)
11. [Object-Oriented Programming](#object-oriented-programming)
12. [Inheritance](#inheritance)
13. [Polymorphism](#polymorphism)
14. [Templates](#templates)
15. [Exception Handling](#exception-handling)
16. [File I/O](#file-io)
17. [Standard Template Library (STL)](#standard-template-library-stl)
18. [Advanced Concepts](#advanced-concepts)

---

## Introduction to C++

C++ is a powerful, high-performance programming language that supports both procedural and object-oriented programming paradigms. It's widely used for system programming, game development, embedded systems, and high-performance applications.

### Key Features:

- **Object-Oriented**: Supports classes, inheritance, polymorphism
- **Performance**: Low-level memory control, compiled language
- **Standard Library**: Rich set of containers, algorithms, and utilities
- **Cross-Platform**: Runs on multiple operating systems
- **Backward Compatible**: Can use C code

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

## Data Types

### Primitive Data Types

**What they are:** Built-in types for storing simple values.

**Data Types:**

1. `bool` - true/false (1/0)
2. `char` - single character
3. `int` - integer numbers
4. `float` - single-precision floating point
5. `double` - double-precision floating point
6. `string` - sequence of characters

- Choose appropriate size for memory efficiency
- `bool` stores 0 (false) or 1 (true)
- `char` can store ASCII characters
- `float` has ~7 decimal digits precision
- `double` has ~15 decimal digits precision
- `string` is not primitive (it's from std library)

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

**Basic Data Types:** Built-in primitives [int, float, double, char, bool, void]

**Derived Data Types:** Created from basic types [array, pointer, reference, function]

**User Defined Data Types:** Custom types [class, struct, union, typedef, using]

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

### Comparison Operators

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

- Short-circuit evaluation: && stops if first operand false
- || stops if first operand true
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
- Logical operators have lower precedence than comparisons
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

```cpp
for (initialization; condition; increment) {
    // code
}
```

- Initialization runs once
- Condition checked before each iteration
- Increment after each iteration

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

**break:** Exit loop or switch

**continue:** Skip to next iteration

**goto:** Jump to labeled statement (avoid)

- break exits innermost loop/switch
- continue skips current iteration
- goto can create spaghetti code - avoid

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

```cpp
void print(int x, int y = 0) {
    cout << x << " " << y << endl;
}
print(5);      // 5 0
print(5, 10);  // 5 10
```

### Arrays and Structures in Functions

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

**What it is:** Multiple functions with same name but different parameters.

- Based on number and/or type of parameters
- Return type alone is not enough for overloading
- Compiler chooses based on arguments
- Avoid ambiguous overloads

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

### Inline Functions

```cpp
inline int square(int x) {
    return x * x;
}
```

### Lambda Functions (C++11+)

**What it is:** Anonymous functions defined inline.

**Syntax:** `[capture](parameters) { body }`

- Useful for short, one-time functions
- Capture variables from surrounding scope
- Can be assigned to variables or passed to functions
- Modern alternative to function pointers

```cpp
auto lambda = [](int x) { return x * 2; };
cout << lambda(5) << endl;  // 10
```

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

```cpp
// Declaration and initialization
int arr[5] = {1, 2, 3, 4, 5};
int arr2[] = {1, 2, 3};  // Size inferred

// Accessing elements
cout << arr[0] << endl;  // First element

// Multi-dimensional
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

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

- `int*`: Pointer to int
- `const int*`: Pointer to constant int
- `int* const`: Constant pointer to int
- `const int* const`: Constant pointer to constant int

### Void Pointers

```cpp
void* ptr;  // Can point to any type
int x = 10;
ptr = &x;
cout << *(int*)ptr << endl;  // Cast back to int*
```

### Function Pointers

```cpp
int add(int a, int b) { return a + b; }

int (*funcPtr)(int, int) = add;
cout << funcPtr(5, 3) << endl;  // 8
```

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
int* arr = new int[10];    // Allocate array
delete[] arr;              // Deallocate array

// Avoid memory leaks!
```

- Local variables are on stack
- `new` allocates on heap, `delete` frees
- Always pair new with delete
- Memory leaks occur when forgetting delete

- Use smart pointers when possible
- Check for null pointers
- Avoid memory leaks

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

**What it is:** Special member function called during object creation.

- Same name as class
- No return type (not even void)
- Usually public
- Called automatically when object created
- Constructor overloading based on parameters
- Default constructor: no parameters
- Copy constructor: `Class(const Class& other)`

### Copy Constructor

**What it is:** A constructor that initializes a new object by copying an existing object of the same class.

**Syntax:**

```cpp
ClassName(const ClassName& other);
```

**Example:**

```cpp
class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}
// Deep copy constructor
    Rectangle(const Rectangle& other) {
        width = new double(*other.width);
        height = new double(*other.height);
    }

    ~Rectangle() {
        delete width;
        delete height;
    }
};

Rectangle r1(10, 5);
Rectangle r2 = r1;  // Calls copy constructor
```

**Key points to remember:**

- Used when passing objects by value, returning objects from functions, or initializing one object from another
- Default copy constructor performs shallow copy of members
- Define a custom copy constructor for classes managing dynamic memory or resources
- If you define a copy constructor, also consider defining copy assignment operator and destructor (Rule of Three)

### `this` Pointer

**What it is:** A pointer available inside non-static member functions that points to the current object.

**Example:**

```cpp
class Point {
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x; // distinguishes member x from parameter x
        this->y = y;
    }
    void print() {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};
```

**Key points to remember:**

- `this` is implicitly available in all non-static member functions
- Use `this->` to disambiguate member variables from parameters
- Useful for returning the current object: `return *this;`
- Cannot be used in static member functions

### Destructors

**What it is:** Special member function called during object destruction.

- Same name as class with `~` prefix
- No return type or parameters
- Called automatically when object goes out of scope
- Used for cleanup (free resources)

### Access Specifiers

1. **public:** Accessible everywhere
2. **private:** Accessible only within class
3. **protected:** Accessible in class and derived classes
4. **Default:** private for classes, public for structs

### Static Members

**What it is:** Members shared by all objects of a class, not tied to any particular instance.

**Example:**

```cpp
class Counter {
public:
    static int count;
    Counter() { count++; }
    static int getCount() {
        return count;
    }
};

int Counter::count = 0;

// Usage
Counter a;
Counter b;
cout << Counter::getCount() << endl; // 2
```

**Key points to remember:**

- `static` data members are shared across all objects
- `static` member functions can be called without an object
- Static functions cannot access non-static members directly
- Initialize static members outside the class definition
- Use `ClassName::member` to access static members

### Friend Functions/Classes

```cpp
class Box {
private:
    int width;
    friend void printWidth(Box b);  // Friend function
};

void printWidth(Box b) {
    cout << b.width << endl;  // Can access private member
}
```

- Encapsulation: hide implementation details
- public interface, private implementation
- protected for inheritance
- Friend functions/classes can access private members

### 4 Pillars of OOP

1. **Abstraction:** Hide complexity, show essentials
2. **Encapsulation:** Bundle data and methods, control access
3. **Inheritance:** Derive new classes from existing ones
4. **Polymorphism:** Objects behave differently based on context

- Abstraction: focus on what, not how
- Encapsulation: data hiding and protection
- Inheritance: code reuse and hierarchy
- Polymorphism: same interface, different behavior

---

## Inheritance

**What it is:** Creating new classes from existing classes.

**Syntax:** `class Derived : public Base { ... };`

- Derived class inherits members from base
- Access specifiers control inheritance visibility
- Base class constructor called first
- Derived class can override base methods

### Basic Inheritance

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

### Virtual Inheritance (Diamond Problem)

```cpp
class A { public: int x; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};  // Only one copy of A
```

---

## Polymorphism

### Compile-time Polymorphism

**Compile-time:** Function overloading, operator overloading

#### Function Overloading

```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};
```

#### Operator Overloading

```cpp
class Complex {
private:
    double real, imag;
public:
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

### Runtime Polymorphism

**Runtime:** Virtual functions

#### Virtual Functions

```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14159 * radius * radius; }
};
```

#### Abstract Classes

Classes with pure virtual functions cannot be instantiated.

- Virtual functions enable dynamic binding
- Base class pointers can point to derived objects
- Override keyword ensures correct overriding
- Pure virtual functions make class abstract

---

## Templates

### Function Templates

**What it is:** Generic functions that work with any data type.

**Syntax:**

```cpp
template <typename T>
T function_name(T param) {
    // code
}
```

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

**What it is:** Generic classes that work with any data type.

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

### Template Specialization

**What it is:** Special implementation for specific types.

- General template for most types
- Specialized version for specific types
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
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);                 // Add element
    vec.insert(vec.begin() + 1, 10); // Insert at position 1
    vec.pop_back();                   // Remove last element

    for (int value : vec) {
        cout << value << " ";
    }
    cout << "\nSize: " << vec.size() << endl;
}
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
