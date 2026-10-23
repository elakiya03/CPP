/*
    typedef is a keyword that is used to assign a new name to any existing data-type.
    here used in structure datatype
*/
#include <iostream>
using namespace std;

typedef struct laptop
{
    int lapid;
    string model;
} lap;

int main()
{
    lap l1;

    cout << "Enter Laptop ID" << endl;
    cin >> l1.lapid;

    cout << "Enter Laptop model name: ";
    cin.ignore(); // To handle newline left in the buffer
    getline(cin, l1.model);

    cout << "\nLaptop Details:\n";
    cout << "LapID: " << l1.lapid << "\n";
    cout << "Model: " << l1.model << "\n";
}