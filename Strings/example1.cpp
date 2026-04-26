#include <iostream>
using namespace std;

int main()
{
    char str[] = "lakshmi loves elaks"; // one way of decaring string in c++ which is inherited from c
    cout << str;

    string s1 = "everything will fall eventually in place";
    cout << s1 << endl;

    string s2("everything will fall eventually in place");
    cout << s2 << endl;

    // to get input
    string s3;
    cout << "Enter your name:";
    cin >> s3;
    cout << s3 << endl;

    string s4;
    cout << "Enter your birthplace:";
    cin.ignore();
    getline(cin, s4);
    cout << s4 << endl;
}