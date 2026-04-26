#include <iostream>
using namespace std;

int main()
{
    try
    {
        int x = -1;
        if (x < 0)
        {
            throw x;
        }
        cout << "I will not be executed" << endl;
    }

    catch (int e)
    {
        cout << "An exception is caught";
    }

    cout << "this is after catch" << endl
         << "so i will be executed";
}