#include <iostream>
using namespace std;

int main()
{
    // 1.Constant Pointer
    int a = 10, b = 11;

    int *const ptr1 = &a;
    *ptr1 = 15;

    // ptr1 = &b; // ❌ Error: Address cannot be changed

    // 2.Pointer to Constant
    const int c = 10;
    // int *const ptr2 = &c; // Cannot modify *ptr
    //*ptr2 = 20;           // ❌ Error
}