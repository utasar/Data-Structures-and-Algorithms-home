// <aside>
// 💡 **Question 1**

// Given two strings s1 and s2, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

// **Example 1:**

// **Input:** s1 = "sea", s2 = "eat"

// **Output:** 231

// **Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.

// Deleting "t" from "eat" adds 116 to the sum.

// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

// </aside>
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the minimum ASCII sum of deleted characters
int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    
    // DP table where dp[i][j] represents the minimum ASCII sum to make s1[0..i-1] and s2[0..j-1] equal
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // Fill the first row (deleting all characters from s1)
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + int(s1[i-1]);
    }
    
    // Fill the first column (deleting all characters from s2)
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j-1] + int(s2[j-1]);
    }
    
    // Fill the rest of the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j] + int(s1[i-1]), dp[i][j-1] + int(s2[j-1]));
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string s1, s2;
    cout << "Enter string one: ";
    cin >> s1;
    cout << "Enter string two: ";
    cin >> s2;
    
    int result = minimumDeleteSum(s1, s2);
    cout << "Minimum ASCII sum of deleted characters: " << result << endl;
    
    return 0;
}
