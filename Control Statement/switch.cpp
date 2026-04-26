/* The switch statement can only evaluate the integer or character value. So, the switch expression should return the values of type int or char only
duplicate case values are not allowed. All the case values must be unique.
*/
#include <iostream>
using namespace std;

int main()
{
    char c = 'B';

    switch (c)
    {
    case 'A':
        cout << "Aashi";
        break;

    case 'B':
        cout << "Lakshmi";
        break;

    default:
        cout << "Invalid";
    }
}