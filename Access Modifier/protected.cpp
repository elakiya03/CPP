#include <iostream>
using namespace std;
class Parent // base class
{
protected:
    int salary; // protected
};
class Child : public Parent // derived class
{
public:
    void setSalary(int s)
    {
        salary = s;
    }
    int getSalary() { return salary; }
};
int main()
{
    Child c;
    c.setSalary(70000);
    cout << c.getSalary();
    return 0;
}