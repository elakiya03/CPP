#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 505;
    }
    catch (...) // catch any type of exception - default
    {
        cout << "Using default catch all block which will catch all the exceptions";
    }
}