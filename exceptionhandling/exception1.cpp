#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    try // test some code
    {
        int x = -1;
        if (x < 0)
        {
            throw runtime_error("Number cannot be negative"); // throw an exception
        }
        cout << "I will not be executed" << endl;
    }

    catch (runtime_error &e) // CORECT - preserves full type, no copy overhead
    {
        cout << "Error occurred: " << e.what() << endl; // caught the err and do smth abt it. If no err, catch block is skipped
    }

    cout << "this is after catch" << endl
         << "so i will be executed";
}