#include <iostream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& p) {
    unordered_map<string, vector<string>> groups;
    vector<vector<string>> result;

    for (string& s : p) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    for (auto& [key, group] : groups) {
        result.push_back(group);
    }
    return result;
}
int main() {
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> matrix = groupAnagrams(v);

    for (auto& x : matrix) {
        for (auto& str : x) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}