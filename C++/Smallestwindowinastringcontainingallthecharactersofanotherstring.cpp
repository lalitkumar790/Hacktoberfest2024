/* Problem: The problem requires finding the smallest substring (or window) in string `s` that contains all the characters of string `p`, including their frequencies. 
  If no such window exists, return "-1". If there are multiple windows of the same size, return the one that appears first. 
  The challenge lies in efficiently finding this window within the constraints of time complexity O(n) and auxiliary space O(n), where n is the length of the strings.
*/

/* Explaination: This C++ solution finds the smallest window in string `s` that contains all characters (including duplicates) of string `p`. 
The algorithm uses two hash maps: one to store the frequency of characters in `p` and another to track the frequency in the current window of `s`. 
  It applies a sliding window technique, where the `end` pointer expands the window and the `start` pointer shrinks it when all characters from `p` are found in the current window. 
  As the window is adjusted, the smallest valid window is recorded. The time complexity is O(n), where `n` is the length of `s`, ensuring efficient performance for large inputs.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string smallestWindow(string s, string p) {
    int len1 = s.size();
    int len2 = p.size();
    
    // Base condition: If p is longer than s, it's impossible to find such a window
    if (len1 < len2) {
        return "-1";
    }
    
    // Hash maps to store frequency of characters in p and the current window in s
    unordered_map<char, int> p_freq;
    unordered_map<char, int> window_freq;

    // Count frequency of each character in p
    for (char ch : p) {
        p_freq[ch]++;
    }

    int start = 0; // Window start pointer
    int min_len = INT_MAX; // Minimum length of the window
    int min_start = 0; // Starting index of the minimum window
    int count = 0; // To check if window contains all characters of p

    // Start expanding the window
    for (int end = 0; end < len1; end++) {
        char end_char = s[end];
        window_freq[end_char]++;
        
        // Check if the current character is part of p and if it contributes to the count
        if (p_freq.find(end_char) != p_freq.end() && window_freq[end_char] <= p_freq[end_char]) {
            count++;
        }
        
        // If all characters from p are matched in the window
        while (count == len2) {
            // Update the minimum window size
            if (end - start + 1 < min_len) {
                min_len = end - start + 1;
                min_start = start;
            }
            
            // Start shrinking the window from the left
            char start_char = s[start];
            window_freq[start_char]--;
            
            // If we lose a necessary character, reduce the count
            if (p_freq.find(start_char) != p_freq.end() && window_freq[start_char] < p_freq[start_char]) {
                count--;
            }
            
            start++; // Move the start pointer to the right
        }
    }
    
    // If no valid window is found
    if (min_len == INT_MAX) {
        return "-1";
    }
    
    // Return the smallest window
    return s.substr(min_start, min_len);
}

int main() {
    // Example 1
    string s1 = "timetopractice";
    string p1 = "toc";
    cout << "Smallest window: " << smallestWindow(s1, p1) << endl;

    // Example 2
    string s2 = "zoomlazapzo";
    string p2 = "oza";
    cout << "Smallest window: " << smallestWindow(s2, p2) << endl;

    return 0;
}
