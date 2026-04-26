#include <iostream>
using namespace std;

class Aashi
{
private:
    int a;

protected:
    int b;

public:
    Aashi()
    {
        a = 10;
        b = 10;
    }
    friend void display(Aashi &a);
};

void display(Aashi &a)
{
    cout << "a = " << a.a << endl
         << "b = " << a.b;
}

int main()
{
    Aashi a;
    display(a);
}