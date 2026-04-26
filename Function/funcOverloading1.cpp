#include <iostream>
using namespace std;
int add(int x, int y) { return x + y; }
double add(double x, double y) { return x + y; }
int main()
{
    int num1 = add(9, 8);
    double num2 = add(9.0, 7.8);
    return 0;
}

// mutiple function can have same name as long as type of parameter are different