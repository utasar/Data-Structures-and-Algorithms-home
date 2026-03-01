// Question 14
// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4

#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&v,int target)
{
    int l=0,r=v.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(v[mid]==target)
        {
            return mid;
        }
       else if(v[mid]>target)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }

    }
    return -1;
}
int main()
{
    cout<<"enter number of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter target"<<endl;
    int target;
    cin>>target;
    int ans=search(v,target);
    if(ans!=-1)
    cout<<"index of target is "<<ans<<endl;
    else
    cout<<"target not found"<<endl;
}

// enter number of elements
// 6
// enter your elements
// -1 0 3 5 9 12
// enter target
// 9
// index of target is 4
