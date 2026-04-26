// only in cpp
#include <iostream>
using namespace std;

int main()
{
    string food = "பழைய சோறு";
    string &name = food;
    cout << name;
    return 0;
}