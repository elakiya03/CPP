#include <iostream>
using namespace std;

int main()
{
    int val[] = {5, 10, 15};
    int *ptr;

    ptr = val; // ptr=&val[0];

    cout << ptr[0] << endl
         << ptr[1] << endl
         << ptr[2] << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }

    /*Points to 0th element of the arr
    p1 = arr;

    Points to the whole array arr
    p2 = &arr; */
}