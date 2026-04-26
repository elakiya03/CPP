#include <iostream>
using namespace std;

int main()
{
    string name = "elakiya";
    string *ptr = &name;

    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr = "aashi";
    cout << *ptr << endl;

    return 0;
}