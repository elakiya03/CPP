#include <iostream>
using namespace std;

class Father
{
public:
    void father() { cout << "From Father" << endl; }
};

class Mother
{
public:
    void mother() { cout << "From mother" << endl; }
};

class Child : public Father, public Mother
{
};

int main()
{
    Child c;
    c.father();

    c.mother();
    return 0;
}