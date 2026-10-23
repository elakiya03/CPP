#include<iostream>
using namespace std;

class Message{
    public:
        string message;
        void setMessage(string m) { message = m; }
        void displayMessage() { cout << message; }
};

int main(){
    Message m;
    m.setMessage("Hello Jimin!");
    m.displayMessage();
}