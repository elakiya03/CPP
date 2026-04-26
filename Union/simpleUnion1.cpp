/*The size of the union is equal to the size of the largest data type.
 The member variables in a union share the same memory location*/
#include <iostream>
using namespace std;

union Data
{
    int i;
    float f;
    char ch;
};

int main()
{
    Data d;

    d.i = 10;
    cout << "Integer: " << &d.i << endl;

    d.f = 5.5;
    cout << "Float: " << d.f << endl;

    d.ch = 'A';
    cout << "Character: " << d.ch << endl;

    // Printing old values after writing a new one
    cout << "\nAfter modifying character:\n";
    cout << "Integer: " << d.i << endl;    // Value is corrupted
    cout << "Float: " << d.f << endl;      // Value is corrupted
    cout << "Character: " << d.ch << endl; // Latest value

    return 0;
}
