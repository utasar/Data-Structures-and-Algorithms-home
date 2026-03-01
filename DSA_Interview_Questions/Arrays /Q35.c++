// <aside>
// 💡 **Question 4**

// Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

// **Example 1:**

// **Input:** nums = [0,1]

// **Output:** 2

// **Explanation:**

// [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// </aside>

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    cout << "Enter your elements: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> m;
    int maxLen = 0, sum = 0;

    // Initialize the map with sum 0 at index -1 to handle edge cases
    m[0] = -1;

    for (int i = 0; i < n; i++) {
        // Convert 0s to -1 to make the sum approach work
        sum += (nums[i] == 1) ? 1 : -1;

        // If this sum has been seen before, it means the subarray between the previous
        // index and the current index has an equal number of 0s and 1s
        if (m.find(sum) != m.end()) {
            maxLen = max(maxLen, i - m[sum]);
        } else {
            // Store the first occurrence of this sum
            m[sum] = i;
        }
    }

    cout << "Maximum length of a contiguous subarray with equal number of 0s and 1s: " << maxLen << endl;

    return 0;
}
