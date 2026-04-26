#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int(25); //initializing the value
    cout << *ptr << endl;
    delete ptr;
}