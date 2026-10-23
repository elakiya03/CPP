#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    auto f = [&a]() // capture by reference
    {
        cout << a++;
    };
    a = 1;
    f();
    return 0;
}