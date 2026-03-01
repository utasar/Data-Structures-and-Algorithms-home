// Question 18
// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
//            ● 0 <= a, b, c, d < n
//            ● a, b, c, and d are distinct.
//            ● nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no. ef elements"<<endl;
    int n;
    cin>>n;
     vector<int>v(n);
     cout<<"enter your elements"<<endl;
     for(int i=0;i<n;i++)
     {
        cin>>v[i];
     }
     vector<vector<int>>ans;
     sort(v.begin(),v.end());
     for(int i=0;i<v.size()-3;i++)
     {
        if(i>0&&v[i]==v[i-1])
        continue;
        for(int j=i+1;j<v.size()-2;j++)
        {
            if(j>i+1&&v[j]==v[j-1])
            continue;
            int l=j+1;
            int r=v.size()-1;
            while(l<r)
            {
                int sum=v[i]+v[j]+v[l]+v[r];
                if(sum==0)
                {
                    ans.push_back({v[i],v[j],v[l],v[r]});
                while(l<r&&v[l]==v[l+1])l++;
                while(l<r&&v[r]==v[r+1])r--;
                 ++l;
                  --r;
                }
                else if(sum<0)
                {
                    l++;
                }
                else 
                r--;

            }
        }

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

// enter no. ef elements
// 6
// enter your elements
// 1 0 -1 0 -2 2
// -2 -1 1 2 
// -2 0 0 2
// -1 0 0 1
