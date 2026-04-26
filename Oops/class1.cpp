#include <iostream>
using namespace std;

class student
{
public:
    int id;
    string name;
    char section;

    // Method 1 - define methods inside class
    void intro()
    {
        cout << "Holo" << endl;
    }

    // Method 2 - define methods outside class but declaration is inside
    string outro(string mgs);
};

string student::outro(string mgs) // with parameters
{
    cout << "Adios" << endl;
}

int main()
{

    student s1;
    s1.id = 1;
    s1.name = "mukesh";
    s1.section = 'A';

    // call the method
    s1.intro();
    s1.outro("Adios");
    
    cout << "ID: " << s1.id << endl
         << "Name: " << s1.name << endl
         << "Section: " << s1.section << endl;
    return 0;
}