// <aside>
// 💡 **Question 9**
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),...,
//  (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// **Example 1:**
// Input: nums = [1,4,3,2]
// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4
// </aside>

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of elements (should be even): ";
    int n;
    cin >> n;

    cout << "Enter the value of each element: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Sort the array to group the smallest values together
    sort(v.begin(), v.end());

    int sum = 0;
    // Sum every second element starting from the first
    for (int i = 0; i < n; i += 2) {
        sum += v[i];
    }

    cout << "The solution is: " << sum << endl;
    return 0;
}

// enter no. of elements
// 4
// enter the value of each element
// 1 4 3 2
// the solution is 4
