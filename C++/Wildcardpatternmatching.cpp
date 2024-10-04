#include <iostream>
#include <vector>
#include <string>
using namespace std;

int wildcardPatternMatching(const string& pattern, const string& str) {
    int m = pattern.length();
    int n = str.length();
    
    // Create a DP table
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // Base case: empty pattern matches empty string
    dp[0][0] = true;
    
    // Handle patterns with '*' at the beginning
    for (int i = 1; i <= m; i++) {
        if (pattern[i - 1] == '*') {
            dp[i][0] = dp[i - 1][0];  // '*' can match an empty string
        }
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];  // Match or '?'
            } else if (pattern[i - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  // '*' can match zero or more characters
            }
        }
    }

    // The result will be in the bottom-right corner of the DP table
    return dp[m][n] ? 1 : 0;
}

int main() {
    string pattern, str;

    // Input for pattern and str
    cout << "Enter the pattern: ";
    cin >> pattern;
    cout << "Enter the string: ";
    cin >> str;

    // Get the result and display it
    int result = wildcardPatternMatching(pattern, str);
    cout << "Output: " << result << endl;

    return 0;
}
