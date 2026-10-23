#include <iostream>
using namespace std;

class Message
{
public:
    int x;
    Message()
    {
        cout << "Default constructor" << endl;
        x = 3;
    }
    Message(int id)
    {
        cout << "Parameterized constructor" << endl;
        x = id;
    }
};

int main()
{
    Message m1;
    cout << m1.x << endl;

    Message m2(20);
    cout << m2.x << endl;
}