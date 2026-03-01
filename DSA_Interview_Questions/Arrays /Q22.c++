// You are given an inclusive range [lower, upper] and a sorted unique integer array
// nums, where all elements are within the inclusive range.

// A number x is considered missing if x is in the range [lower, upper] and x is not in
// nums.

// Return the shortest sorted list of ranges that exactly covers all the missing
// numbers. That is, no element of nums is included in any of the ranges, and each
// missing number is covered by one of the ranges.

// Example 1:
// Input: nums = [0,1,3,50,75], lower = 0, upper = 99
// Output: [[2,2],[4,49],[51,74],[76,99]]

// Explanation: The ranges are:
// [2,2]
// [4,49]
// [51,74]
// [76,99]

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int lower,higher;
    cout<<"enter lower range"<<endl;
    cin>>lower;
    cout<<"enter higher range"<<endl;
    cin>>higher;
    vector<vector<int>>ans;
     
    cout<<"the out put for the ranges is"<<endl;
        if(v[0]!=lower)
        {
            ans.push_back({lower,v[0]-1});
        }
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1]-v[i]==1)
        {
            continue;
        }
        else
        {
            ans.push_back({v[i]+1,v[i+1]-1});
        }

    }
    if(v[n-1]<=higher)
    {
        ans.push_back({v[n-1]+1,higher});
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

// enter no. of elements
// 5
// enter elements
// 0 1 3 50 75
// enter lower range
// 0
// enter higher range
// 99
// the out put for the ranges is
// 2 2 
// 4 49 
// 51 74 
// 76 99 
