/* Enter input from the keyboard
>> = extraction operator
<< = insertion operator
 */
#include <iostream>
using namespace std;

int main()
{
    // Validate text input
    string name;
    do
    {
        cout << "Enter your name" << endl;
        getline(cin, name);
    } while (name.empty()); // keep asking ntill user enters smth
    cout << "Hi " << name << "!" << endl;

    // Validate integer input
    int num;
    cout << "Enter a number: ";
    while (!(cin >> num)) // keep asking untill user enters valid number
    {
        cout << "Invalid Input. Try Again";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "You entered: " << num << endl;

    // Validate number range
    do
    {
        cout << "Choose any num btw 1 to 50" << endl;
        cin >> num;
    } while (num < 1 || num > 50);
    cout << "You choose: " << num;
}