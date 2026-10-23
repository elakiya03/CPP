/*
An inline function in C++ is a function that the compiler attempts to expand
 in place, meaning its function call is replaced with its actual code during compilation.
 This can reduce function call overhead and improve performance for small functions.
*/

#include <iostream>
using namespace std;

inline int square(int x){ return x * x;}
int main()
{
    // instead of calling the function, it replaces the call with 5 * 5.
    cout << "Square of 5 = " << square(5) << endl;
    cout << "square of 10 = " << square(10) << endl;
}