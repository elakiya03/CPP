#include <iostream>

void swap(int &a, int &b)
{
    a = a ^ b; // a now holds info about both
    b = a ^ b; // b = (a^b)^b = a^(b^b) = a^0 = a
    a = a ^ b; // a = (a^b)^a = b^(a^a) = b^0 = b
}

// Note: only works when a and b are different memory locations
// xorSwap(arr[i], arr[i]) would zero it out — be careful!

int main()
{
    int a, b;
    std::cin >> a >> b;

    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}