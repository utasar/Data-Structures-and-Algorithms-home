// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the size of the matrix: ";
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));  // Create a n x n matrix
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            v[top][i] = num++;
        }
        top++;  // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            v[i][right] = num++;
        }
        right--;  // Move the right boundary left

        // Traverse from right to left along the bottom row, if still in bounds
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                v[bottom][i] = num++;
            }
            bottom--;  // Move the bottom boundary up
        }

        // Traverse from bottom to top along the left column, if still in bounds
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                v[i][left] = num++;
            }
            left++;  // Move the left boundary right
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
