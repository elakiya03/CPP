/*using constructor inside structure*/

#include <iostream>
using namespace std;

struct mark
{
    int m;
    mark(int x) { m = x; }
};

int main()
{
    mark m1(3);
    cout << m1.m;
}