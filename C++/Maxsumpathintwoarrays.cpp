#include <iostream>
#include <vector>
using namespace std;

int maxSumPath(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    int totalSum = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // If arr1's element is smaller, add it to sum1
        if (arr1[i] < arr2[j]) {
            sum1 += arr1[i];
            i++;
        }
        // If arr2's element is smaller, add it to sum2
        else if (arr1[i] > arr2[j]) {
            sum2 += arr2[j];
            j++;
        }
        // If elements are equal, we found a common element
        else {
            // Add the maximum of the two sums and reset them
            totalSum += max(sum1, sum2) + arr1[i];
            sum1 = 0;  // Reset sum1
            sum2 = 0;  // Reset sum2
            i++;
            j++;
        }
    }

    // Add remaining elements in arr1
    while (i < arr1.size()) {
        sum1 += arr1[i];
        i++;
    }

    // Add remaining elements in arr2
    while (j < arr2.size()) {
        sum2 += arr2[j];
        j++;
    }

    // Add the maximum of the two remaining sums to total
    totalSum += max(sum1, sum2);

    return totalSum;
}

int main() {
    int n, m;

    // Input for first array
    cout << "Enter the size of the first array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter " << n << " distinct integers for the first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Input for second array
    cout << "Enter the size of the second array: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter " << m << " distinct integers for the second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Calculate and output the maximum sum path
    cout << "Maximum Sum Path: " << maxSumPath(arr1, arr2) << endl;

    return 0;
}
