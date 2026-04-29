#include <iostream>
using namespace std;

// double ended queue - add and remove elements from both ends and also index acess
int main()
{
    deque<string> names = {"a", "b", "c", "d", "e"};

    for (string s : names)
    {
        cout << s << endl;
    }

    // first
    cout << names.front() << endl;
    // back
    cout << names.back() << endl;
    // position
    cout << "At 3 specific : " << names.at(2) << endl;

    // add beginning
    names.push_front("z");

    // add end
    names.push_back("d");

    for (string s : names)
    {
        cout << s << endl;
    }

    //remove
    names.pop_back();
    names.pop_front();

    // size
    cout << "size of the deque: " << names.size();

    return 0;
}