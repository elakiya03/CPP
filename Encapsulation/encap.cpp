// Encapsulation is to make sure that sensitive data is hidden from users. You must declare class attibutes as private. If you want others to read and modify the value of private meneber you can provide public get and set

#include <iostream>
using namespace std;

class emp
{
private:
    int salary;

public:
    void setSalary(int s)
    {
        salary = s;
    }

    int getSalary()
    {
        return salary;
    }
};
int main()
{
    emp e;
    e.setSalary(70000);
    cout << e.getSalary();
    return 0;
}