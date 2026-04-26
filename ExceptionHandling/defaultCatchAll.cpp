#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 'a';
    }
    catch (...) // catch all - default
    {
        cout << "Using default catch all blockk which will catch all the exceptions";
    }
}