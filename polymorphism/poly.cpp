#include <iostream>
using namespace std;
class Animal
{
public:
    void display() { cout << "Animals makes sound" << endl; }
};
class Wolf : public Animal
{
public:
    void display() { cout << "Wolf be like: Awooo" << endl; }
};
class Elephant : public Animal
{
public:
    void display() { cout << "Elephant be like: pawoo" << endl; }
};
int main()
{
    Animal a;
    Wolf w;
    Elephant e;

    a.display();
    w.display();
    e.display();
    return 0;
}