#include <iostream>
using namespace std;

template <typename T> // avoid repeating the same logic for different datatypes

// T represents placeholder for a datatype

class A
{
private:
    T num;

public:
    void set(T n) { num = n; }
    T get() { return num; }
};
int main()
{
    A<int> a;
    a.set(50);
    cout << a.get() << endl;

    A<string> b;
    b.set("elaks");
    cout << b.get() << endl;

    return 0;
}