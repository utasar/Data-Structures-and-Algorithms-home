// <aside>
// 💡 **Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

// Note that you must do this in-place without making a copy of the array.

// **Example 1:**
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// </aside>

#include<bits/stdc++.h>
using namespace std;
void change(vector<int>&v)
{
   
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==0)
            {
                swap(v[j],v[j+1]);
            }

        }
    }
}
int main()
{
    cout<<"enter the no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    change(v);
      for(int i=0;i<n;i++)
    {
     cout<<v[i]<<" ";
    }
}

// enter the no. of elements
// 5
// enter your elements
// 0 1 0 3 12
// 1 3 12 0 0 
