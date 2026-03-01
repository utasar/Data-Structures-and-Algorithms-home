// <aside>
// 💡 **Q5.** You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
//  representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// **Example 1:**
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

// **Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// </aside>

#include<bits/stdc++.h>
using namespace std;
vector<int>merge(vector<int>&one,int n,vector<int>&two,int x,vector<int>&ans)
{
    int i=0;
    int k=0;
    int j=0;
    while(i<n&&j<x)
    {
        if(one[i]<two[j])
        {
            ans[k]=one[i];
            i++;
        }
        else{
            ans[k]=two[j];
            j++;
        }
        k++;
    }
    if(i<n)
    {
        while(i<n)
        {
            ans[k]=one[i];
            i++;
            k++;
        }
    }
    if(j<x)
    {
         while(j<x)
        {
        {
            ans[k]=two[j];
            j++;
            k++;
        } 
        }
    }
    return ans;
}
int main()
{
   cout<< "enter the no of elements in first array"<<endl;
   int n;
   cin>>n;
   cout<<"enter the elements of first array"<<endl;
   vector<int>one(n);
   for(int i=0;i<n;i++)
   {
    cin>>one[i];
   }
   cout<< "enter the no of elements in second array"<<endl;
   int x;
   cin>>x;
   cout<<"enter the elements of second array"<<endl;
   vector<int>two(x);
   for(int i=0;i<x;i++)
   {
    cin>>two[i];
   }
   cout<<"the merged sorted array is"<<endl;
vector<int>ans(x+n);
ans=merge(one,n,two,x,ans);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
}
// enter the no of elements in first array
// 3
// enter the elements of first array
// 1 2 3
// enter the no of elements in second array
// 3
// enter the elements of second array
// 2 5 6
// the merged sorted array is
// 1 2 2 3 5 6
