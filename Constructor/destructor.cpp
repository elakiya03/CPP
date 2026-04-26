#include <iostream>
using namespace std;

class Message
{
public:
    string message;

    Message() { cout << "Hi constructor here!" << endl; }
    ~Message() { cout << "Hi Destructor here!" << endl; }
};

int main()
{
    Message m;
}