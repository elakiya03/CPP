#include <iostream>
using namespace std;

class A {
   public:
    int x;

    A(int val) {
        x = val;
    }

    // Copy constructor
    A(const A& obj) {
        x = obj.x;
    }
};

int main() {
    A a1(10);
    A a2 = a1;  // copy constructor called

    cout << a2.x;  // 10
}