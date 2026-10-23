#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void show()
    {
        cout << "I am a parent" << endl;
    }

    void display()
    {
        cout << "I am on parent class" << endl;
    }
};

class Child : public Parent
{
public:
    void show()
    {
        cout << "I am a child because of virtual" << endl;
    }

    void display()
    {
        cout << "I am on a child";
    }
};

int main()
{
    Parent *p;
    Child c;
    p = &c; // parent points to child

    p->show();
    p->display();
}