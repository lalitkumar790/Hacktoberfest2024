/* Problem Explanation:
Given an array height that represents the heights of buildings, the task is to count how many buildings can see the sunrise. The sun rises from the start (left) side of the array, so a building can see the sunrise if its height is strictly greater than all the previous buildings' heights (to its left).

Example:
Input: height = [7, 4, 8, 2, 9]
Output: 3
Explanation:

Building 1 (height 7) can see the sunrise because it is the first building.
Building 2 (height 4) cannot see the sunrise because Building 1 (height 7) is taller.
Building 3 (height 8) can see the sunrise because it is taller than all the buildings to its left.
Building 4 (height 2) cannot see the sunrise because Building 3 (height 8) is taller.
Building 5 (height 9) can see the sunrise because it is taller than all the buildings to its left.
Input: height = [2, 3, 4, 5]
Output: 4
Explanation: All buildings can see the sunrise because each building is taller than the previous one.

Approach:
Iterate through the array from left to right.
Keep track of the maximum height encountered so far.
If the current building is taller than the previous maximum height, it can see the sunrise.
Increment the count of buildings that can see the sunrise.

*/

#include <iostream>
#include <vector>
using namespace std;

int countBuildingsWithSunrise(const vector<int>& height) {
    int count = 1;  // The first building always sees the sunrise
    int max_height = height[0];  // Initialize max height to the height of the first building

    for (int i = 1; i < height.size(); i++) {
        if (height[i] > max_height) {
            count++;  // This building can see the sunrise
            max_height = height[i];  // Update max height
        }
    }

    return count;
}

int main() {
    vector<int> height = {7, 4, 8, 2, 9};
    cout << "Number of buildings that can see the sunrise: " << countBuildingsWithSunrise(height) << endl;

    vector<int> height2 = {2, 3, 4, 5};
    cout << "Number of buildings that can see the sunrise: " << countBuildingsWithSunrise(height2) << endl;

    return 0;
}
