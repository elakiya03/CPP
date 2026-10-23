// sort 0s, 1s, 2s inplace - using 3 ptrs
#include <iostream>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 2) {
            swap(arr[high--], arr[mid]);
        } else {
            mid++;
        }
    }
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort012(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}