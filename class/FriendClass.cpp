#include <iostream>
using namespace std;

class Aashi
{
private:
    string name;

protected:
    string birthPlace;

public:
    Aashi()
    {
        name = "Aashi";
        birthPlace = "Theni";
    }
    friend class Elaks;
};

class Elaks
{
public:
    void display(Aashi &a)
    {
        cout << "I am friend class of " << a.name << " and she is in " << a.birthPlace << endl;
    }
};

int main()
{
    Aashi a;
    Elaks e;
    e.display(a);
}