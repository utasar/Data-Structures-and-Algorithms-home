// <aside>
// 💡 **Question 8**

// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// </aside>

#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n == 2) return true;  // Two points always form a straight line

    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int x1 = coordinates[1][0], y1 = coordinates[1][1];
    
    for (int i = 2; i < n; ++i) {
        int x2 = coordinates[i][0], y2 = coordinates[i][1];
        
        // Check if the slope between (x0, y0) and (x1, y1) is the same as between (x1, y1) and (x2, y2)
        if ((y1 - y0) * (x2 - x1) != (y2 - y1) * (x1 - x0)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<vector<int>> coordinates = {{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}};
    cout << (checkStraightLine(coordinates) ? "true" : "false") << endl;
    return 0;
}
