// Phoorin Chinphuad 66070501043
#include <iostream>
#include <climits>

using namespace std;

int crossMaxSum(int arr[], int left, int mid, int right) {
    // Include elements on the left of mid
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    // Include elements on the right of mid
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int left, int right) {
    // Base case: only one element
    if (left == right)
        return arr[left];

    // Find the midpoint of the array
    int mid = (left + right) / 2;

    // Recursively find the maximum sum in the left, right, and crossing the mid
    int leftSum = maxSubArraySum(arr, left, mid);
    int rightSum = maxSubArraySum(arr, mid + 1, right);
    int crossSum = crossMaxSum(arr, left, mid, right);

    return max(leftSum, max(rightSum, crossSum));
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int maxSum = maxSubArraySum(arr, 0, size - 1);

    cout << maxSum;

    return 0;
}
