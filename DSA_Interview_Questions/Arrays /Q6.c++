// <aside>
// 💡 **Q6.** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// **Example 1:**
// Input: nums = [1,2,3,1]

// Output: true

// </aside>

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&v,unordered_map<int,int>&mp)
{
    for(int i=0;i<v.size();i++)
    {
        if(mp[v[i]]==1)
        {
            return true;
        }
        else
        {
            mp[v[i]]=mp[v[i]]+1;
        }
    }
    return false;
}
int main()
{
    cout<<"enter the no of elements in your array"<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements in your array"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"the solution is -:"<<endl;
    unordered_map<int,int>mp;
    bool ans=check(v,mp);
    if(ans)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

}
// enter the no of elements in your array
// 4
// enter the elements in your array
// 1 2 3 1
// the solution is -:
// true

// enter the no of elements in your array
// 4 
// enter the elements in your array
// 1 2 3 4
// the solution is -:
// false
