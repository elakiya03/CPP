

// ─────────────────────────────────────────
//  15. ABSOLUTE value without branching
// ─────────────────────────────────────────
int absoluteVal(int n)
{
    // arithmetic right shift fills with the sign bit
    // positive: n >> 31 = 00...0 (all zeros)
    // negative: n >> 31 = 11...1 (all ones = -1 in two's complement)
    int mask = n >> 31;

    // for positive: (n + 0) ^ 0 = n  (unchanged)
    // for negative: (n + (-1)) ^ (-1)
    //             = (n - 1) ^ 0xFFFFFFFF
    //             = bitwise NOT of (n-1) = -n
    return (n + mask) ^ mask;
}

// ─────────────────────────────────────────
//  19. CHECK if two numbers have
//      opposite signs
// ─────────────────────────────────────────
bool oppositeSign(int a, int b)
{
    // XOR of sign bits:
    // same sign   → sign bit XOR = 0 → result positive
    // diff signs  → sign bit XOR = 1 → result negative (< 0)
    return (a ^ b) < 0;
}

// Round down to nearest power of 2
int floorPow2(int n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n - (n >> 1);
}

// ─────────────────────────────────────────
//  12. FAST multiply by power of 2
// ─────────────────────────────────────────
int multiplyByPow2(int n, int k)
{
    // n << k  ==  n * (2^k)
    // shifting left by 1 doubles the number
    // shifting left by k multiplies by 2^k
    return n << k;
}

// ─────────────────────────────────────────
//  13. FAST divide by power of 2 (floor)
// ─────────────────────────────────────────
int divideByPow2(int n, int k)
{
    // n >> k  ==  n / (2^k), floored
    // shifting right by 1 halves the number
    // works for positive numbers — for negatives use arithmetic shift
    return n >> k;
}