#include <iostream>
using namespace std;

// method 1
namespace name
{
    int x = 4;
}

// method 2
using namespace name1
{
    int y = 3;
}

int main()
{
    cout << name::x;

    // 2
    cout << y;  //no need to write name1::y
    return 0;
}