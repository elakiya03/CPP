#include <iostream>
using namespace std;

int main()
{
    string name = "elakiya";
    cout << "First Char: " << name.at(0) << endl;
    cout << "Second char: " << name.at(1) << endl;
    cout << "Last char: " << name.at(name.length() - 1) << endl;
    return 0;
}