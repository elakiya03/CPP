#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter: " << endl;

    cin >> x;
    if (x < 0)
    {
        cerr << "Error occured." << endl;
    }

    clog << "log message" << endl;
    return 0;
}