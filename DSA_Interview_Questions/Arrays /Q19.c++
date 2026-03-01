// Question 19
// Given a sorted array of distinct integers and a target value, return the index if the
// target is found. If not, return the index where it would be if it were inserted in
// order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

#include<bits/stdc++.h>
using namespace std;
int bin_search(vector<int>&v,int target)
{
    int l=0;
    int h=v.size()-1;
    while(l<h)
    {
        int mid=(l+h)/2;
        if(v[mid]==target)
        return mid;
        else if(v[mid]<target)
        l=mid+1;
        else
        h=mid-1;
    }
    return -1;
}
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
    cout<<"enter target value"<<endl;
    int target;
    cin>>target;
    int ans=bin_search(v,target);
    cout<<ans;
}
// enter no. of elements
// 4
// enter your elements
// 1 3 5 6
// enter target value
// 5
// 2
