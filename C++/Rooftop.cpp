/*
Problem Explanation:
You are given an array representing the heights of consecutive buildings. Your task is to find the maximum number of consecutive steps where each next building has a strictly higher height than the previous one. A "step" is defined as moving from one building to its next adjacent building.

You can only move to the next building if its height is greater than the current one.
Your goal is to count the maximum number of consecutive buildings where the height strictly increases.
Example 1:
Input: arr[] = [1, 2, 2, 3, 2]
Output: 1
Explanation:

From 1 to 2 is an increase (1 step).
From 2 to 2 is not an increase, so the count resets.
From 2 to 3 is an increase (1 step). Hence, the maximum number of consecutive steps with an increasing altitude is 1.
Example 2:
Input: arr[] = [1, 2, 3, 4]
Output: 3
Explanation:

From 1 to 2 is an increase (1 step).
From 2 to 3 is an increase (1 more step).
From 3 to 4 is an increase (another step). Hence, the maximum number of consecutive steps is 3.
Approach:
Initialize a counter to keep track of the consecutive steps.
Iterate through the array, comparing each element with its previous one:
If the current element is greater than the previous one, increment the step counter.
Otherwise, reset the step counter.
Track the maximum steps encountered during the iteration.

*/



//Solution :

#include <iostream>
#include <vector>
using namespace std;

int maxSteps(vector<int>& arr) {
    int max_steps = 0;   // Variable to store the maximum steps
    int current_steps = 0; // Variable to store the current increasing sequence length
    
    // Iterate through the array from the second element
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            // If current building is taller than the previous one, increase current steps
            current_steps++;
            max_steps = max(max_steps, current_steps);  // Update max steps if needed
        } else {
            current_steps = 0;  // Reset step count if no increase in height
        }
    }
    
    return max_steps;
}

int main() {
    // Example 1
    vector<int> arr1 = {1, 2, 2, 3, 2};
    cout << "Maximum consecutive steps (Example 1): " << maxSteps(arr1) << endl;  // Output: 1
    
    // Example 2
    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Maximum consecutive steps (Example 2): " << maxSteps(arr2) << endl;  // Output: 3
    
    return 0;
}
