#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> names = {"a", "b", "c", "d", "e"};

    // isEmpty;
    cout << "isEmpty? : " << names.empty() << endl;

    for (string n : names)
    {
        cout << n << endl;
    }

    // first
    cout << names.front() << endl;
    // back
    cout << names.back() << endl;

    // add beginning
    names.push_front("z");

    // add end
    names.push_back("d");

    // size
    cout << "size of the list: " << names.size();

    // remove beginning
    names.pop_front();

    // cannot access elements through index
    return 0;
}