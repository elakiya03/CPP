#include <iostream>
using namespace std;

template <typename T> //typename T 
T add(T a, T b) { return a + b; }
int main()
{
    cout << add(2, 3) << endl;
    cout << add(2.3, 6.7) << endl;
    cout << add<string>("e", "l") << endl;
    return 0;
}