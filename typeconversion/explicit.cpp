/*
Explicit type conversion, also called type casting is the conversion of one type of data to another type manually by a programmer.

This method is inherited by C++ from C. The conversion is done by explicitly defining the required type in
front of the expression in parenthesis. This can be also known as forceful casting.
*/
#include <iostream>
using namespace std;

int main()
{
    double x = 1.2;

    int sum = (int)x + 1;

    cout << sum << endl;
}