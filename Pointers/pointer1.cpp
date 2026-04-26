/*
Pointers are - said as the variables that can store the address of another variable as its value.




*/
#include <iostream>
using namespace std;

int main()
{
    int var = 20;

    int *ptr;

    // note that data type of ptr and var must be same
    ptr = &var;

    cout << "Value at ptr = " << ptr << endl; //Its ponting to the addr of var variable
    cout << "Value at var = " << var << endl;
    cout << "Value at *ptr = " << *ptr;         //prints its content
}