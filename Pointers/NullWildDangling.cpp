#include <iostream>
using namespace std;

int main(){
    // Null pointer - A pointer that does not point to any memory location
    int *ptr = NULL;

    // Wild pointer - A pointer that is declared but not initialized.( contains garbage address)
    int *ptr;

    //Dangling pointer - A pointer that points to deleted or deallocated memory allocation
    int *ptr = new int(5);
    delete ptr;
    //To prevent issues, set the pointer to NULL after delete.
    ptr = NULL;

    //For arrays
    int *arr = new int[5];
    delete[] arr;
}