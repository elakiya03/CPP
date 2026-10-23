#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string text;
    ifstream file("f.txt");

    while(getline(file,text)){
        cout<<text;
    }

    file.close();

    return 0;
}