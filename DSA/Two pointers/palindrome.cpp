// Time: O(n) and Space: O(1)
//  not O(n^2)
#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // skip all alpha-numeric
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }

    return true;
}
int main() {
    string s;
    getline(cin, s);

    cout << (isPalindrome(s) ? "Yes" : "No") << endl;

    return 0;
}

// Eg: A man, a plan, a canal: Panama
// Palindrome: Yes