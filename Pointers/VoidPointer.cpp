/* Void Pointer (Generic Pointer) - A pointer that can store addresses of any data type but cannot be directly dereferenced.


*/

#include <iostream>
using namespace std;

int main()
{
    void *ptr;

    int a = 10;
    ptr = &a;
    // accessing interger variable
    cout << static_cast<int *>(ptr) << endl;
    cout << *static_cast<int *>(ptr) << endl; // Converts void* to int* and dereferences it to get the value.

    char c = 'E';
    ptr = &c;
    // accessing char variable
    cout << *static_cast<char *>(ptr) << endl; // Converts void* to char* and dereferences it to get the value.
}