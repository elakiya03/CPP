#include <iostream>
using namespace std;

int main()
{
    auto add = [](int a, int b)
    {
        cout << "hi elaks" << endl;
        return a + b;
    };
    cout << add(2, 6);
    return 0;
}