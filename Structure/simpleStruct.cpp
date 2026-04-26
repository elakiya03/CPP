#include <iostream>
using namespace std;

struct laptop
{
    int lapid;
    string model;
};

int main()
{
    laptop l1;
    
    cout<<"Enter Laptop ID"<<endl;
    cin>>l1.lapid;
    
    cout << "Enter Laptop model name: ";
    cin.ignore(); // To handle newline left in the buffer
    getline(cin, l1.model);

    cout << "\nLaptop Details:\n";
    cout << "LapID: " << l1.lapid << "\n";
    cout << "Model: " << l1.model << "\n";
}