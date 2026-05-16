#include <iostream>
using namespace std;

int binarySearch(vector<int>& arr, int tgt) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == tgt)
            return mid;
        else if (arr[mid] > tgt)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << binarySearch(arr, target) << endl;
    return 0;
}