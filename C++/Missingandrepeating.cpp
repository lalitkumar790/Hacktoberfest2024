/*Problem Explanation:
You are given an unsorted array of integers, where each integer is between 1 and n (inclusive), and exactly one number in the range [1, n] is missing, 
while another number occurs twice. The task is to find the missing number 'A' and the repeating number 'B' in an efficient manner, with expected time complexity O(n) 
and constant auxiliary space O(1).

For example:

Input: [2, 2] → Output: 2 1 (Repeating: 2, Missing: 1)
Input: [1, 3, 3] → Output: 3 2 (Repeating: 3, Missing: 2)
Approach:
Sum Difference Method (Mathematical Approach):
Calculate the sum of the first n natural numbers and the sum of their squares.
Use the given array to find the actual sum of the elements and their squares.
Based on the differences between the expected and actual sums, deduce the missing and repeating numbers.


*/

#include <iostream>
#include <vector>
using namespace std;

void findMissingAndRepeating(const vector<int>& arr, int n) {
    // Initialize variables to store the sum and sum of squares
    long long sum_n = n * (n + 1) / 2;              // Sum of first n natural numbers
    long long sum_n_sq = n * (n + 1) * (2 * n + 1) / 6;  // Sum of squares of first n numbers

    long long sum = 0, sum_sq = 0;

    // Traverse the array and compute the actual sum and sum of squares
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sum_sq += (long long)arr[i] * arr[i];
    }

    // Calculate the differences
    long long diff_sum = sum_n - sum;                // A - B
    long long diff_sq_sum = sum_n_sq - sum_sq;       // A^2 - B^2

    // Using the formula A^2 - B^2 = (A - B)(A + B)
    long long sumAB = diff_sq_sum / diff_sum;        // A + B

    // Now, solve for A and B
    int missing = (diff_sum + sumAB) / 2;
    int repeating = sumAB - missing;

    // Output the missing and repeating numbers
    cout << "Repeating number: " << repeating << ", Missing number: " << missing << endl;
}

int main() {
    vector<int> arr = {1, 3, 3};
    int n = arr.size();
    findMissingAndRepeating(arr, n);
    return 0;
}
