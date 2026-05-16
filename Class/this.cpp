#include <iostream>
using namespace std;

class counter {
    int count;

   public:
    counter(int count) {
        this->count = count;  // disambiguous memeber vs parameter s
        // same name -> confusion
        // this->count - obj count
    }

    counter& increment() { //reference to same object
        count++;
        return *this;  // return the current object itself
    }

    // this = pointer to obj
    //*this = actual object

    counter& add(int n) {
        count += n; //modify object
        return *this;
    }

    void print() {
        cout << count << endl;
    }
};

int main() {
    counter c(0);
    c.increment().increment().add(5).print();  // method of chaninig -> prints 7
    return 0;
}