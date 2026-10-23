#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("f.txt");

    file << "Hello Elakiya\n";
    file << "This is file handling in C++";

    file.close();

    return 0;
}