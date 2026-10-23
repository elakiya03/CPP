#include <iostream>
using namespace std;

int main()
{
    int n = 7;

    // if block executed when the number is even
    if (n % 2 == 0)
        cout << "Even";

    // else block executed when the number is not even
    else
        cout << "Odd";
}