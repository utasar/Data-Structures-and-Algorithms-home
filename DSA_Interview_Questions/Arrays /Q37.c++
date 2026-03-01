// <aside>
// 💡 **Question 6**

// An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

// Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

// **Example 1:**

// **Input:** changed = [1,3,4,2,6,8]

// **Output:** [1,3,4]

// **Explanation:** One possible original array could be [1,3,4]:

// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.

// Other original arrays could be [4,3,1] or [3,1,4].

// </aside>

#include<bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    // If the array length is odd, return an empty array
    if (changed.size() % 2 != 0) return {};

    // Sort the array
    sort(changed.begin(), changed.end());

    unordered_map<int, int> freq;
    vector<int> original;

    // Count the frequency of each element
    for (int num : changed) {
        freq[num]++;
    }

    // Iterate through the sorted array
    for (int num : changed) {
        // If the current number has already been paired, skip it
        if (freq[num] == 0) continue;

        // Check if there exists a double of the current number
        if (freq[num * 2] == 0) return {};  // No valid pair, return empty

        // Add the current number to the original array
        original.push_back(num);

        // Decrease the frequency of the current number and its double
        freq[num]--;
        freq[num * 2]--;
    }

    return original;
}

int main() {
    cout << "Enter the number of elements: " << endl;
    int n;
    cin >> n;

    vector<int> v(n);
    cout << "Enter your elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> original = findOriginalArray(v);

    // If the original array is empty, it means no valid solution was found
    if (original.empty()) {
        cout << "[] (No valid original array)" << endl;
    } else {
        for (int i = 0; i < original.size(); i++) {
            cout << original[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
