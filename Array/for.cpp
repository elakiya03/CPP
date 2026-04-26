#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    string name = "Elakiya";

    for (int i : arr)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (char c : name)
    {
        cout << c << "\t";
    }
    return 0;
}