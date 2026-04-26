#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        // if i become 3 then skip the rest body of loop and move next iteration
        if (i == 2)
        {
            continue;
        }

        cout << i << endl;
    }
}