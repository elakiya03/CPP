#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr1 = &a;     // pointer to integer
    int **ptr2 = &ptr1; // pointer to pointer

    cout << *ptr1 << endl
         << **ptr2 << endl;
}