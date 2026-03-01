// <aside>
// 💡 **Question 1**
// Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

// **Example 1:**

// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

// Output: [1,5]

// **Explanation:** Only 1 and 5 appeared in the three arrays.

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no of elements of first array"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
     cout<<"enter no of elements of second array"<<endl;
    int m;
    cin>>m;
    cout<<"enter your elements"<<endl;
    vector<int>w(m);
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
     cout<<"enter no of elements of third array"<<endl;
    int o;
    cin>>o;
    cout<<"enter your elements"<<endl;
    vector<int>z(o);
    for(int i=0;i<o;i++)
    {
        cin>>z[i];
    }
    vector<int>ans;
     unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        mp[w[i]]++;
    }
    for(int i=0;i<o;i++)
    {
        mp[z[i]]++;
        if(mp[z[i]]==3)
        ans.push_back(z[i]);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

}

// enter no of elements of first array
// 5
// enter your elements
// 1 2 3 4 5
// enter no of elements of second array
// 5
// enter your elements
// 1 2 5 7 9
// enter no of elements of third array
// 5
// enter your elements
// 1 3 4 5 8
// 1
// 5
