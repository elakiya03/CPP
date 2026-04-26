#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    auto f = [a]() // capture by value
    {
        cout << a;
    };
    f();
    return 0;
}