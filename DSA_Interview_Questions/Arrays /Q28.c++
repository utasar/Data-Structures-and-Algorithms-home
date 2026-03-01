// <aside>
// 💡 **Question 6**
// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**

// Input: nums = [-4,-1,0,3,10]

// Output: [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100]

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int l=0;
    int h=v.size()-1;
    int i=0;
    while(l<=h)
    {
        if((v[l]*v[l])<(v[h]*v[h]))
        {
            ans.push_back(v[h]*v[h]);
            h--;
        }
        else{
            ans.push_back(v[l]*v[l]);
            l++;
        }
        i++;
    }
    for(int j=n-1;j>=0;j--)
    {
        cout<<ans[j]<<" ";
    }
}
// enter no of elements
// 5
// enter your elements
// -4 -1 0 3 10
// 0 1 9 16 100 
