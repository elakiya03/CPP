#include <iostream>
using namespace std;

vector<int> reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = reverseArray(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}