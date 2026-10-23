#include <iostream>
using namespace std;

void printBinary(int n, int bits = 8)
{
    // iterate from the highest bit down to bit 0
    for (int i = bits - 1; i >= 0; i--)
    {
        // shift n right by i positions, isolate last bit with & 1
        cout << ((n >> i) & 1);
        // print a space every 4 bits for readability
        if (i % 4 == 0 && i != 0)
            cout << " ";
    }
    cout << "  (" << n << ")" << endl;
}
int main()
{
    int n;
    std::cin >> n;
    printBinary(n);
    return 0;
}