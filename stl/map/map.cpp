#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> students = {{1, "elaks"}, {2, "aashi"}, {3, "muku"}};

    // access
    cout << students[3] << endl;
    cout << students.at(3) << endl;

    // add
    students.insert({5, "virat"});

    // remove
    students.erase(1);

    students.size();

    for (auto s : students)
    {
        cout << s.first << " - " << s.second << endl;
    }

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        cout << it->first << " - " << it->second << endl;
    }
    return 0;
}