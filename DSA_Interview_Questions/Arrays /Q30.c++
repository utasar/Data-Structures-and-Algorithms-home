// <aside>
// 💡 **Question 30**
// You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

// Count and return *the number of maximum integers in the matrix after performing all the operations*

// **Example 1:**

// ![q4.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d0890d0-7bc7-4f59-be8e-352d9f3c1c52/q4.jpg)

// **Input:** m = 3, n = 3, ops = [[2,2],[3,3]]

// **Output:** 4

// **Explanation:** The maximum integer in M is 2, and there are four of it in M. So return 4.

// </aside>

#include <iostream>
#include <vector>
#include <algorithm> // for std::min

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int min_a = m;
    int min_b = n;
    
    // Iterate through all operations and find the minimum ai and bi
    for (const auto& op : ops) {
        min_a = min(min_a, op[0]);
        min_b = min(min_b, op[1]);
    }
    
    // The result is the area of the smallest overlap
    return min_a * min_b;
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};
    
    cout << "Number of maximum integers in the matrix: " << maxCount(m, n, ops) << endl;
    
    return 0;
}
