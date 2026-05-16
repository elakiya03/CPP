#include <iostream>
using namespace std;

// Clear rightmost set bit
int clearRightmost(int n) { return n & (n - 1); }

int main()
{
    int n;
    cin >> n;
    cout << clearRightmost(n) << endl;
    return 0;
}