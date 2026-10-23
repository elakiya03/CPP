#include <iostream>
using namespace std;

// ─────────────────────────────────────────
//  1. CHECK if bit k is set (1 or 0)
// ─────────────────────────────────────────
bool isBitSet(int n, int k) // retur
{
    return (n >> k) & 1;
    // shift n right by k positions
    // AND with 1 to isolate the last bit

    // n = 13 = 1101
    // k = 2
    // 1101 >> 2 = 0011
    // 0011 & 0001 = 0001 = 1 → bit 2 IS set

    // k = 1
    // 1101 >> 1 = 0110
    // 0110 & 0001 = 0000 = 0 → bit 1 is NOT set
}

// ─────────────────────────────────────────
//  2. SET bit k — force it to 1
// ─────────────────────────────────────────
int setBit(int n, int k)
{
    return n | (1 << k);
    // 1 << k creates a mask with only bit k set
    // OR forces that bit to 1, leaves others unchanged

    // n = 1001 (9), k = 1
    // 1 << 1  = 0010
    // 1001 | 0010 = 1011 = 11
}

// ─────────────────────────────────────────
//  3. CLEAR bit k — force it to 0
// ─────────────────────────────────────────
int clearBit(int n, int k)
{
    return n & ~(1 << k);
    // 1 << k  = 0...010...0  (only bit k is 1)
    // ~(1<<k) = 1...101...1  (only bit k is 0)
    // AND clears bit k, preserves everything else

    // n = 1101 (13), k = 2
    // 1 << 2   = 0100
    // ~(1<<2)  = 1011
    // 1101 & 1011 = 1001 = 9
}

// ─────────────────────────────────────────
//   4. TOGGLE bit k — flip it
//  ─────────────────────────────────────────
int toggleBit(int n, int k)
{
    // XOR truth table:  0^1=1  1^1=0  0^0=0  1^0=1
    // XOR with 1 flips the bit
    // XOR with 0 leaves the bit unchanged
    // Step 1: mask = 1 << k  →  only bit k is 1
    // Step 2: XOR n with mask → only bit k gets flipped
    return n ^ (1 << k);
}

// ─────────────────────────────────────────
//  5. GET value of bit k  (0 or 2^k)
// ─────────────────────────────────────────
int getBitValue(int n, int k)
{
    // unlike isBitSet (which returns 0 or 1),
    // this returns the actual positional value
    // e.g. bit 3 → returns 8, not 1
    return n & (1 << k);
}

int main()
{

    std::cout << isBitSet(13, 0) << std::endl; // 1  (13 = ...1101, bit 0 = 1)
    std::cout << isBitSet(13, 1) << std::endl; // 0  (13 = ...1101, bit 1 = 0)
    std::cout << isBitSet(13, 2) << std::endl; // 1  (13 = ...1101, bit 2 = 1)
    std::cout << isBitSet(13, 3) << std::endl; // 1  (13 = ...1101, bit 3 = 1)

    std::cout << setBit(9, 1) << std::endl; // 11  (set bit 1 in 1001 → 1011)
    std::cout << setBit(9, 2) << std::endl; // 13  (set bit 2 in 1001 → 1101)

    std::cout << clearBit(13, 2) << std::endl; // 9   (clear bit 2 in 1101 → 1001)
    std::cout << clearBit(13, 0) << std::endl; // 12  (clear bit 0 in 1101 → 1100)
    return 0;
}