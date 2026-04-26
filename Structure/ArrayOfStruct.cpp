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

    Candidate c[n]; // Correctly defining an array of `Candidate` structs

    for (int i = 0; i < n; i++) // Using indexed loop
    {
        cout << "\nEnter details for Candidate " << i + 1 << ":\n";
        cout << "Enter your ID: ";
        cin >> c[i].c_id;
        cin.ignore(); // To handle leftover newline from previous input

        cout << "Enter your name: ";
        getline(cin, c[i].c_name); // Using getline to take full name input

        cout << "Enter your exam center: ";
        getline(cin, c[i].c_center);
    }

    cout << "\nCandidate Details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "ID: " << c[i].c_id << ", Name: " << c[i].c_name
             << ", Exam Center: " << c[i].c_center << endl;
    }
}
