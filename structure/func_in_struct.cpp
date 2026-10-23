/*
This program deal with using member function inside struct*/

#include <iostream>
using namespace std;
struct mark
{
    int m;
    void set(int temp) { m = temp; }
    void display() { cout << m << endl; }
};
int main()
{
    mark m1;
    // Before setting value
    m1.display();

    m1.set(2);

    // after setting value
    m1.display();
}