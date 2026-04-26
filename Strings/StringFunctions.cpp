/* this program contains function of string*/
#include <iostream>
using namespace std;

int main()
{
    string s1 = "Everything";
    string s2 = "Everyone";

    // length of the string
    cout << "Length of the string 1 : " << s1.length() << endl;
    cout << "Length of the string 2 : " << s2.length() << endl;

    // accessing char at an index
    cout << "character at index - 3 : " << s1.at(3) << endl;

    // concantation of strings
    cout << "Concatenating two strings : " << s1.append(s2) << endl;

    // compare two strings
    cout << "Comparing two strings : " << s1.compare(s2) << endl;

    // to check whether a given character or a substring is present in the string or a part of string
    cout << s1.find("thing") << endl;

    // return substring of the string
    cout << s1.substr(0, 3) << endl;

    // insert
    // replace
    // erase
}