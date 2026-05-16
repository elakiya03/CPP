#include <iostream>
using namespace std;

// Check if odd
string isOdd(int n) { return n & 1 ? "Yes" : "No"; }
// Last bit is 1 → odd, 0 → even

int main()
{
    int n;
    cin >> n;
    cout << isOdd(n) << endl;
    return 0;
}