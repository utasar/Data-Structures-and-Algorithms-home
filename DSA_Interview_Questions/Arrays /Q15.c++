// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

#include<bits/stdc++.h>
using namespace std;

bool checkMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            decreasing = false;  // Can't be decreasing
        }
        if (nums[i] < nums[i - 1]) {
            increasing = false;  // Can't be increasing
        }
    }

    // The array is monotonic if it is either increasing or decreasing
    return increasing || decreasing;
}

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool ans = checkMonotonic(v);
    cout << ans << endl;
}

// enter the no. of elements
// 4 
// enter the elements
// 1 4 2 3
// 0
