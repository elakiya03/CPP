/*
Find the maximum of two given numbers
*/
#include <iostream>
using namespace std;
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
    int a = 20;
    int b = 10;
    //int m = max(a, b);

    cout << "Maximum of two number - " << max(a, b) << endl;
}