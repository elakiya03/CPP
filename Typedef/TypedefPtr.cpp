#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 19;

    typedef int *intPtr;

    intPtr ptrA = &a;
    intPtr ptrB = &b;

    cout << *ptrA << endl
         << *ptrB << endl;
}