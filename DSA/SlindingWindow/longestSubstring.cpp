#include <iostream>
#include <unordered_set>
using namespace std;

int longestSubStringWithoutRepeatingChar(string s) {
    int maxLen = 0;
    int left = 0;
    int i = 0;

    unordered_set<char> set;

    while (i < s.length()) {
        if (set.find(s[i]) == set.end()) {
            set.insert(s[i]);
            i++;
            maxLen = (maxLen, i - left);
        } else {
            set.erase(s[left++]);
        }
    }
    return maxLen;
}
int main() {
    string s;
    getline(cin, s);
    cout << longestSubStringWithoutRepeatingChar(s) << endl;

    return 0;
}