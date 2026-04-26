/*
    this program deals with using structure pointer to array of structure
*/
#include <iostream>
using namespace std;

struct Candidate
{
    int c_id;
    string c_name;
    string c_center;
};

int main()
{
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;
    cin.ignore();

    Candidate *ptr = new Candidate[n]; // Dynamically allocated array

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Candidate " << i + 1 << ":\n";

        cout << "Enter your ID: ";
        cin >> (ptr + i)->c_id;
        cin.ignore();

        cout << "Enter your name: ";
        getline(cin, (ptr + i)->c_name);

        cout << "Enter your exam center: ";
        getline(cin, (ptr + i)->c_center);
    }

    cout << "\nCandidate Details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "ID: " << (ptr + i)->c_id
             << ", Name: " << (ptr + i)->c_name
             << ", Exam Center: " << (ptr + i)->c_center << endl;
    }

    delete[] ptr; // Free dynamically allocated memory
    return 0;
}
