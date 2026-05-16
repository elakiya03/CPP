#include <iostream>
using namespace std;

class message {
   public:
    string name;
    int id;

    message() {  // default constructor
        cout << "Hi nga!" << endl;
    }

    //FAST - directly initializes memebers (one step)
    message(string n) : name(n) {}  // paramterized constructor

    message(int m);  // constructor declaration
};

message::message(int m) {  // constructor definition outside class
    id = m;
}

int main() {
    message m;  // this will call the construtor

    message m1("elaks");
    cout << m1.name;

    message m2(2);
    cout << m2.id;
    return 0;
}