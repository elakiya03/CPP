// C++ program to demonstrate the use of goto statement

/*  Note Use of goto is generally avoided in modern programming practices because it may disturb the readability of the code and make the code error-prone, although it is still valid and used occasionally
 */
#include <iostream>
using namespace std;

int main()
{

    int age = 17;
    if (age < 18)
        goto Noteligible;
    else
        cout << "You can vote!";

Noteligible:
    cout << "You are not eligible to vote!\n";
    return 0;
}
