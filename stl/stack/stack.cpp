#include <iostream>
using namespace std;

int main()
{
    stack<string> names; // cannot add elements to stack at the time of declaration

    //add top
    names.push("a");
    names.push("b");
    names.push("c");
    names.push("d");
    names.push("e");

    // top element
    cout << names.top() << endl;

    // remove
    names.pop();

    // top element
    cout << names.top() << endl;

    // size
    cout << "size of the stack: " << names.size();
    return 0;
}