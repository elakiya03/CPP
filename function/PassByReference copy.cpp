#include <iostream>
using namespace std;

void swap(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}
int main()
{
    int x = 5;
    int y = 10;
    cout << "Before swapping\n"
         << x << " " << y << endl;

    // Call the 'swap' function with pass-by-reference
    // parameters Values of 'x' and 'y' are modified in the
    // calling code because references are used
    swap(x, y);
    cout << "After swapping\n"
         << x << " " << y << endl;
}