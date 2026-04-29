#include <iostream>
using namespace std;

template <typename T, typename U>

void printPair(T first, U second)
{
    cout << first << " and " << second << endl;
}

int main()
{
    printPair(42, "jk");
    printPair(1, 8.9);
    return 0;
}