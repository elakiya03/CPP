// C++ Proram to illustrate the use of integer literals
#include <iostream>
using namespace std;

int main()
{

    // Integer literals of different bases
    int dec = 42;

    //(Prefix: 0)
    int oct = 052;

    //(Prefix: 0x or 0X)
    int hex = 0x2A;

    //(Prefix: 0b or 0B)
    int bin = 0b101010;

    //(Suffix : l or L) 
    long int lint = 42L;

    //(Suffix: u or U)
    unsigned int uint = 42U;

    //(Suffix: ll or LL)
    long long int llint = 42LL;

    // printing every value
    cout << dec << endl;
    cout << oct << endl;
    cout << hex << endl;
    cout << bin << endl;
    cout << lint << endl;
    cout << uint << endl;
    cout << llint;

    return 0;
}
