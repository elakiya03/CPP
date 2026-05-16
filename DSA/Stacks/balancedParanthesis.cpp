#include <iostream>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char i : str) {
        if (i == '(' || i == '{' || i == '[') {
            s.push(i);
        }

        else if (i == ')' || i == '}' || i == ']') {
            if (s.empty()) return false;

            char c = s.top();
            s.pop();
            if (c == '(' && i != ')') return false;
            if (c == '{' && i != '}') return false;
            if (c == '[' && i != ']') return false;
        }
    }
    return s.empty();
}
int main() {
    string str = "((){}{[]})";
    cout << (isBalanced(str) ? "Yes" : "No") << endl;
    string str2 = "((){}{[(]})";
    cout << (isBalanced(str2) ? "Yes" : "No") << endl;
    return 0;
}