#include <iostream>
using namespace std;

class Number
{
public:
    int value;

    Number(int v)
    {
        value = v;
    }

    Number operator+(Number n)
    {
        return Number(value + n.value);
    }
};

int main()
{
    Number n1(3), n2(1);
    Number n3 = n1 + n2;
    cout << "After adding objects of the class" << endl;
    cout << n3.value;
}