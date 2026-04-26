/*
Implicit type conversion (also known as coercion) is the conversion of one type of data to another type automatically by the compiler when needed
*/
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    char c = 'a'; // ASCII - 97

    // 'c' implicitly converted to int. ASCII
    i += c;

    float f = i + 1.3;

    cout << "i - " << i << endl
         << "c - " << c << endl
         << "f - " << f;
}