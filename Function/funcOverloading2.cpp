#include <iostream>
using namespace std;
int add(int x, int y) { return x + y; }
int add(int x, int y, int z) { return x + y + z; }
int main()
{
    int num1 = add(9, 8);
    int num2 = add(9, 7, 8);

    cout << num1 << endl
         << num2 << endl;
    return 0;
}

// mutiple function can have same name as long as number of parameter are different