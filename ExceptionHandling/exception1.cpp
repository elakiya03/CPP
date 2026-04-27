#include <iostream>
using namespace std;

int main()
{
    try // test some code
    {
        int x = -1;
        if (x < 0)
        {
            throw x; //throw an exception
        }
        cout << "I will not be executed" << endl;
    }

    catch (int e)
    {
        cout << "Error occurred: " << e << endl; //caught the err and do smth abt it. If no err, catch block is skipped
    }

    cout << "this is after catch" << endl
         << "so i will be executed";
}