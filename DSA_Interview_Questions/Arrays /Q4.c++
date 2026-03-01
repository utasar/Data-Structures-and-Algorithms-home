// <aside>
// 💡 You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// **Example 1:**
// Input: digits = [1,2,3]
// Output: [1,2,4]

// **Explanation:** The array represents the integer 123.

// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

// </aside>

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int carry = 1;  // Start with carry as 1 because we need to increment by 1
    for (int i = n - 1; i >= 0; i--) {
        v[i] = v[i] + carry;
        if (v[i] >= 10) {
            v[i] = v[i] % 10;
            carry = 1;
        } else {
            carry = 0;
            break;  // No further carry, so we can stop
        }
    }

    // If carry is still 1 after processing all digits, we need to add a '1' at the beginning
    if (carry) {
        v.insert(v.begin(), 1);
    }

    cout << "The new array is: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
// Enter the number of elements: 3
// Enter the elements: 9 9 9
// The new array is: 1 0 0 0 
