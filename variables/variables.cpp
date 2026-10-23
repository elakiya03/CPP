#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int age = 24; //constant
    auto mgs = "sorry"; //compiler auto detects the types

    string name;
    cout << "Enter a string: " << endl;
    // cin >> name;     ----------> reads only single word and stops at spaces.
    getline(cin, name); // ------> reads entire line
    cout << "string: " << name << endl;

    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    cout << "int: " << num << endl;

    char c;
    cout << "Enter a character: " << endl;
    cin >> c;
    cout << "char: " << c << endl;

    bool isFine = false;
    cout << "Enter a boolean (0 or 1): " << endl;
    cin >> isFine;  // cin dont accept true or false. only 0/1
    cout << "bool: " << isFine << endl;

    float dec;
    cout << "Enter a float: " << endl;
    cin >> dec;
    cout << "float: " << dec << endl;

    double d;
    cout << "Enter a double: " << endl;
    cin >> d;
    cout << "double: " << d << endl;

    short s;
    cout << "Enter a short: " << endl;
    cin >> s;
    cout << "short: " << s << endl;

    long ll;
    cout << "Enter a long: " << endl;
    cin >> ll;
    cout << "long: " << ll << endl;
}