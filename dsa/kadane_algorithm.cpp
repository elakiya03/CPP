// maximum subarray sum(both positive and negative numbers)

#include <iostream>
using namespace std;

int maxSubArraySum(vector<int>& arr) {
    int sum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        sum = max(arr[i], sum + arr[i]);
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSubArraySum(arr);

    return 0;
}