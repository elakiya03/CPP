#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> names = {"elaks", "muku", "taylor", "virat", "jm"};

    // add
    names.insert("elaks");

    // sorted automatically ascending
    for (string s : names)
    {
        cout << s << endl;
    }

    // sorting - descending
    set<string, greater<string>> names_ = {"elaks", "muku", "taylor", "virat", "jm"};

    cout << "-----------" << endl;
    for (string s : names_)
    {
        cout << s << endl;
    }

    // remove specific element
    names_.erase("jm");

    cout << names_.size();
    return 0;
}