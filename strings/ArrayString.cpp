/*Array of strings using char pointer*/
#include <iostream>
using namespace std;
int main()
{
    const char *str[] = {"Wei wuxian", "lan zhan", "xiao zhan", "wang yibo"};

    for (const char *c : str)
    {
        cout << c << endl;
    }
}