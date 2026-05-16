#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (char c : t) {
        freq[c - 'a']--;
    }

    for (int i : freq) {
        if (i != 0) return false;
    }

    return true;
}
int main() {
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    cout << (isAnagram(s, t) ? "Yes" : "No") << endl;

    return 0;
}