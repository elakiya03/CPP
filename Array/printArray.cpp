#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    arr[0] = -1;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);  //printf statement will also work in C++
    }
}