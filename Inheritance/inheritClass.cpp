// Inheritance allows one class to reuse attributres and methods from another class.
#include <iostream>
using namespace std;

class Parent
{
public:
    void displayP() { cout << "This is parent" << endl; }
};

class Child : public Parent
{
public:
    void displayC() { cout << "This is Child" << endl; }
};

int main()
{
    Child c;
    c.displayP(); // calls parent
    c.displayC(); // calls child
}