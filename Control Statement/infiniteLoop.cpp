#include <iostream>
using namespace std;

int main()
{
    for (;;)
        cout << "This loop will run forever" << endl;

    while (1)
        cout << "This loop will run forever.\n";

    do
        cout << "This loop will run forever" << endl;
    while (1);
}