// Part of polymorphism
#include <iostream>
using namespace std;
class A
{
public:
    virtual void shout() { cout << "Shouting" << endl; }
};
class B : public A
{
public:
    void shout() { cout << "Shutting" << endl; }
};
int main()
{
    A *a;
    B b;
    a = &b;
    a->shout();   // virtual - the call uses the actual obj function and not just the ptr type
    (*a).shout(); // another way yo call pointer obj
    return 0;
}