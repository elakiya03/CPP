#include <iostream>
using namespace std;

int main()
{
    vector<string> names;

    // add
    names.push_back("elaks");
    names.push_back("virat");
    names.push_back("bethel");
    names.push_back("washi");
    names.push_back("padikkal");

    // loop
    for (string n : names)
    {
        cout << n << endl;
    }

    cout << "First element: " << names.front() << endl;
    cout << "Last element: " << names.back() << endl;
    cout << "At 3 specific : " << names.at(2) << endl;

    // remove
    names.pop_back();

    // size
    cout << names.size() << endl;

    vector<string>::iterator it;
    for (it = names.begin(); it != names.end(); ++it)
    {
        cout << *it << endl;
    }

    // iterator
    for (auto it = names.rbegin(); it != names.rend(); ++it)
    {
        cout << *it << endl;
    }

    // sort
    sort(names.begin(), names.end());
    // reverse sort
    sort(names.rbegin(), names.rend());

    // search
    auto it1 = find(names.begin(), names.end(), "elaks");
    if (it1 != names.end())
    {
        cout << "Found" << endl;
    }

    // small
    auto it2 = min_element(names.begin(), names.end());
    cout << *it2 << endl;

    // large
    auto it3 = max_element(names.begin(), names.end());
    cout << *it3 << endl;
    return 0;
}