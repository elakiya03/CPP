// not in c
#include <iostream>
using namespace std;

void ffunction(string name = "Elakiya") // default parameter value
{
    cout << name << endl;
}
int main()
{
    ffunction("elaks"); // argument
    ffunction();        // no argument
    return 0;
}