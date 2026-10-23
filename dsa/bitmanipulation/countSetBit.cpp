#include <iostream>
using namespace std;

// count no of 1's

int countSetBit_1(int n)
{
    int count = 0;
    while (n)
    {
        count = count + (n & 1); // check if last bit is 1
        n >>= 1;                 // shift right — discard the bit we just checked
                                 // brings the next bit into position 0
    }

    return count;
}

int countSetBit_2(int n)
{
    int count = 0;

    while (n)
    {
        n = n & n - 1; // always clears Right Most 1's
        count++;
    }
    return count;
}

// in built function
int countSetBit_3(int n)
{
    return __builtin_popcount(n); // for int
    // __builtin_popcountll(n)          // for long long
}

// ─────────────────────────────────────────
//  8. GET rightmost set bit position
// ─────────────────────────────────────────
int rightmostSetBitPos(int n)
{
    if (n == 0)
        return -1; // no set bits

    int pos = 0;
    // keep shifting right until we find a 1
    while ((n & 1) == 0)
    {
        n >>= 1;
        pos++;
    }
    return pos;
}

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

int main()
{
    int n;
    cin >> n;

    cout << countSetBit_1(n) << endl;
    cout << countSetBit_2(n) << endl;
    cout << countSetBit_3(n) << endl;

    cout << rightmostSetBitPos(n) << endl;

    cout << isolateRightmost(n) << endl;

    return 0;
}