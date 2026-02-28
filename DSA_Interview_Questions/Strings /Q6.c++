// Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.

// A **shift** on s consists of moving the leftmost character of s to the rightmost position.

// - For example, if s = "abcde", then it will be "bcdea" after one shift.

// **Example 1:**

// **Input:** s = "abcde", goal = "cdeab"

// **Output:**

// true

#include<bits/stdc++.h>
using namespace std;

bool canBecomeGoal(string s, string goal) {
    int n = s.size();
    int m = goal.size();
    
    if (n != m) return false;
    
    s = s + s;  // Concatenate s with itself to simulate all possible rotations.
    
    // Check if goal is a substring of the doubled string
    if (s.find(goal) != string::npos) {
        return true;
    }
    
    return false;
}

int main() {
    string s, goal;
    cin >> s >> goal;
    
    bool result = canBecomeGoal(s, goal);
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}
