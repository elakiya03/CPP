#include <iostream>
using namespace std;

class p
{
public:
    int age;
    string name;

    void display()
    {
        cout << "He is " << name << " and his age is " << age << endl;
    }
};

int main()
{
    p p1;
    p1.age = 17;
    p1.name = "brownie";
    p1.display();
}