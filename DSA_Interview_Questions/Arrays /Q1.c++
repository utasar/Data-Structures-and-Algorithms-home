
// 💡 **Q1.** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// **Example:**
// Input: nums = [2,7,11,15], target = 9
// Output0 [0,1]

// **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1]

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of elements: ";
    int x;
    cin >> x;

    vector<int> v(x);
    cout << "Enter your elements:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }

    cout << "Enter target element: ";
    int target;
    cin >> target;

    map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < x; i++) {
        int complement = target - v[i];

        if (mp.find(complement) != mp.end()) {
            ans.push_back(mp[complement]);
            ans.push_back(i);
            break;
        }

        mp[v[i]] = i;
    }

    if (ans.size() == 2) {
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
// Enter the number of elements: 4
// Enter your elements:
// 2 7 11 15
// Enter target element: 9
// Indices: 0 1
