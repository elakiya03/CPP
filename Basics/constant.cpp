/*
We can only initialize the constant variable in C++ at the time of its declaration. If we do not initialize it at
the time of declaration, it will store the garbage value that was previously stored in the same memory.
*/

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;

    cout << a << endl;

    return 0;
}
