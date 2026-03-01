// <aside>
// 💡 **Q3.** Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// **Example 1:**
// Input: nums = [1,3,5,6], target = 5

// Output: 2

// </aside>

#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&v,int target,int n)
{
  int size=n;
  int start=0;
  while(start<size)
  {
  int mid=(size+start)/2;
    if(v[mid]==target)
    {
        return mid;
    }
    else if(v[mid]>target)
    {
        size=mid-1;
    }
    else
    start=mid+1;
  }
  return -1;
}
int main()
{
    cout<<"enter no. of elements"<<endl;
    int n;
    cin>>n;
    vector<int>v;
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        v.push_back(y);
    }
    cout<<"enter your target value"<<endl;
    int target;
    cin>>target;
    int ans=binary_search(v,target,n);
    if(ans==-1)
    {
        cout<<"element not found"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
}
// enter no. of elements
// 4
// enter elements
// 1 3 5 6
// enter your target value
// 5
// 2
