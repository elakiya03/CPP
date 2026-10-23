#include <iostream>
using namespace std;
class Parent
{
public:
    void display() { cout << "Hi from parent" << endl; }
};

class Child : public Parent
{
public:
    void display() {} //display this both obj
};

class GChild : public Child
{
};

int main()
{
    GChild obj;
    obj.display();

    Child c;
    c.display();

    return 0;
}