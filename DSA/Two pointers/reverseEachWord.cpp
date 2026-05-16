#include <iostream>
using namespace std;

string reverseEachWord(string s) {
    int start = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || i == s.length()) {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    return s;
}
int main() {
    string s;
    getline(cin, s);

    cout << reverseEachWord(s) << endl;

    return 0;
}