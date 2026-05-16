#include <iostream>
using namespace std;

int main()
{
    queue<string> names; // cannot add elements to stack at the time of declaration

    // add end
    names.push("a");
    names.push("b");
    names.push("c");
    names.push("d");
    names.push("e");

    // access first
    cout << names.front() << endl;
    // access back
    cout << names.back() << endl;

    // remove beginning
    names.pop();

    // size
    cout << "size of the queue: " << names.size();

    return 0;
}