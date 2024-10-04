#include <iostream>
#include <vector>
using namespace std;

vector<int> findSortedSubsequenceOfSize3(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return {}; // Not enough elements
    }

    // Initialize variables
    int first = INT_MAX, second = INT_MAX;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= first) {
            first = arr[i]; // Update first
        } else if (arr[i] <= second) {
            second = arr[i]; // Update second
        } else {
            // Found the third element, return the subsequence
            result.push_back(first);
            result.push_back(second);
            result.push_back(arr[i]);
            return result;
        }
    }
    return {}; // No valid subsequence found
}

int main() {
    vector<int> arr1 = {1, 2, 1, 1, 3};
    vector<int> result1 = findSortedSubsequenceOfSize3(arr1);
    if (!result1.empty()) {
        cout << "Output: 1\n";
    } else {
        cout << "Output: 0\n";
    }

    vector<int> arr2 = {1, 1, 3};
    vector<int> result2 = findSortedSubsequenceOfSize3(arr2);
    if (!result2.empty()) {
        cout << "Output: 1\n";
    } else {
        cout << "Output: 0\n";
    }

    return 0;
}
