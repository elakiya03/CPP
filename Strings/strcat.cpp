#include <iostream>
// #include <string>

using namespace std;

int main()
{
    string firstname = "elaks";
    string lastname = "sundar";

    // Method 1 - to concatenate strings
    cout << firstname + " " +lastname << endl;

    // Method 2 - using append()
    string fullname = firstname.append(" ").append(lastname);
    cout << fullname << endl;

    return 0;
}
