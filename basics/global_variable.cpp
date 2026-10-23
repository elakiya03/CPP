/*
This program illustrate how to access global variable if both global and local have the same identifier.
*/
#include <iostream>
using namespace std;

// Global x
int x = 3;

int main()
{

    // Local x
    int x = 10;

    // Printing the global x
    cout << ::x << endl;

    // Printing the local x
    cout << x;
    return 0;
}
