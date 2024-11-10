#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

using namespace std;

int Operation = 0; // Counter for the number of operations

// Function to find the minimum value in an array using divide and conquer
int findMin(const vector<int>& arr, int left, int right) {
    // Base case: only one element
    if (left == right) {
        return arr[left];
    }

    // Find the midpoint
    int mid = left + (right - left) / 2;

    // Recursively find the minimum in both halves
    int min1 = findMin(arr, left, mid);
    int min2 = findMin(arr, mid + 1, right);

    // Increment the operation count for the comparison
    cout << left << " " << right << endl;
    Operation++;

    // Return the smaller of the two minimums
    return min(min1, min2);
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19, 1, 20};

    int n = arr.size();
    if (n == 0) {
        cout << "Array is empty." << endl;
        return 0;
    }

    int minValue = findMin(arr, 0, n - 1); // Call the function with the full range
    cout << "Minimum value in the array is: " << minValue << endl;
    cout << "Number of operations (comparisons): " << Operation << endl; // Output the number of operations

    return 0;
}
