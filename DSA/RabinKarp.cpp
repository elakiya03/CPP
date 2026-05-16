#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int base = 26;
    int mod = 1e9 + 7;

    long long patternHash = 0;
    long long windowHash = 0;
    long long highestPower = 1;

    // calculate highest power: base^(m-1)
    for (int i = 0; i < m - 1; i++) {
        highestPower = (highestPower * base) % mod;
    }

    // hash pattern and first window
    for (int i = 0; i < m; i++) {
        patternHash =
            (patternHash * base + (pattern[i] - 'a' + 1)) % mod;

        windowHash =
            (windowHash * base + (text[i] - 'a' + 1)) % mod;
    }

    // slide window
    for (int i = 0; i <= n - m; i++) {
        // if hashes match
        if (patternHash == windowHash) {
            bool match = true;

            // verify actual string
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << "Pattern found at index "
                     << i << endl;
            }
        }

        // compute next window hash
        if (i < n - m) {
            // remove left character
            windowHash =
                (windowHash -
                 ((text[i] - 'a' + 1) * highestPower) % mod + mod) %
                mod;

            // shift left and add new character
            windowHash =
                (windowHash * base +
                 (text[i + m] - 'a' + 1)) %
                mod;
        }
    }
}

int main() {
    string text, pattern;

    cin >> text;
    cin >> pattern;

    rabinKarp(text, pattern);

    return 0;
}