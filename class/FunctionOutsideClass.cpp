#include <iostream>
using namespace std;

class Emp
{
public:
    int Eid;
    string Ename;

    Emp(int id, string name)
    {
        Eid = id;
        Ename = name;
    }
    void display();
};

void Emp::display()
{
    cout << "He is employee working here." << endl
         << "His name is " << Ename
         << " - " << Eid << endl;
}

int main()
{
    Emp e1(1, "purple");
    e1.display();
}