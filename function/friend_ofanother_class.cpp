#include <iostream>
using namespace std;

class Aashi; // Forward declaration

class Elaks
{
public:
    void display(Aashi &a);
}; // Missing semicolon added here

class Aashi
{
private:
    string name;

protected:
    string place;

public:
    Aashi()
    {
        name = "Aashi";
        place = "Theni";
    }
    friend class Elaks; // Correctly declaring Elaks as a friend class
    //friend void Elaks::display(Aashi &a);  - Another way to declare memeber function of as friend function
};

void Elaks::display(Aashi &a)
{
    cout << "Name: " << a.name << endl
         << "Place: " << a.place << endl;
}

int main()
{
    Elaks e;
    Aashi a;
    e.display(a);
    return 0;
}
