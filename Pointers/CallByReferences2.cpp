// call by refernce with refernces arguments
#include <iostream>
using namespace std;

inline int square(int& x) { return x *= x; }
int main()
{
    int num = 8;
    cout << "value of num before function call " << num << endl;
    square(num);
    cout << "value of num after function call " << num << endl;
}