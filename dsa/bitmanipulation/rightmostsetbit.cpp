#include <iostream>
using namespace std;

// ─────────────────────────────────────────
//  9. ISOLATE the rightmost set bit
//     returns a number with ONLY that bit
// ─────────────────────────────────────────
int isolateRightmost(int n)
{
    // Two's complement trick:
    // -n flips all bits then adds 1
    //  n = ...XYZ 1 000  (rightmost 1 with zeros after)
    // -n = ...ABC 1 000  (different high bits, same low pattern)
    // n&-n = 000...1 000  (only the rightmost 1 survives)
    return n & (-n);
}

// n=12=1100: -12=...0100, 1100&0100=0100 ✓
int main()
{
    int n;
    cin >> n;
    cout << isolateRightmost(n) << endl;
    return 0;
}
