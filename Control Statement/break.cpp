#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 5; i++)
    {
        // if i become 3 then break the loop and move to next statement out of loop
        if (i == 2)
        {
            break;
        }

        cout << i << endl;
    }
}