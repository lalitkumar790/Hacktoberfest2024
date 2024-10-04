#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& val, const vector<int>& wt) {
    int N = val.size();
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i - 1] <= j) {
                // Include the item
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            } else {
                // Exclude the item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum value is in the last cell
    return dp[N][W];
}

int main() {
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> val(N);
    vector<int> wt(N);

    cout << "Enter the values of the items: ";
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < N; i++) {
        cin >> wt[i];
    }

    int maxValue = knapsack(W, val, wt);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
