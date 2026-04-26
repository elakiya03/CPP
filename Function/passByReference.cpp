// will not work in c
#include <iostream>
using namespace std;

void interchange(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{

    int x = 10, y = 9;
    interchange(x, y);
    cout << x << endl
         << y << endl;
    return 0;
}