#include <iostream>
using namespace std;

class Parent
{
public:
    void displayP() { cout << "This is parent"; }
};

class Child : public Parent
{
public:
    void displayC() { cout << "This is Child"; }
};

int main()
{
    Child c;
    c.displayP();
    c.displayC();
}