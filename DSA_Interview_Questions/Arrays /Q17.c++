// Question 17
// Given an integer array nums of length n and an integer target, find three integers
// in nums such that the sum is closest to the target.
// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2

// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter your target"<<endl;
    int target;
    cin>>target;
    sort(v.begin(),v.end());
    int closest_sum=INT_MAX;
    for(int i=0;i<v.size()-2;i++)
    {
        int l=i+1;
        int r=v.size()-1;
        while(l<r)
        {
            int curr_sum=v[l]+v[r]+v[i];
           if (abs(target - curr_sum) < abs(target - closest_sum)) {
                closest_sum = curr_sum;
            }
            
            // Move the pointers based on the comparison between currentSum and target
            if (curr_sum < target) {
                ++l;
            } else if (curr_sum > target) {
                --r;
            } else {
                // If currentSum is exactly equal to target, return the currentSum
                return curr_sum;
            }
        }
    }
    cout<<closest_sum;

}
// enter no. of elements
// 4
// enter your elements
// -1 2 1 -4
// enter your target
// 1
// 2
