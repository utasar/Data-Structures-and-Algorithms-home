// <aside>
// 💡 **Question 24**

// Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

// - answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
// - answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

// **Note** that the integers in the lists may be returned in **any** order.

// **Example 1:**

// **Input:** nums1 = [1,2,3], nums2 = [2,4,6]

// **Output:** [[1,3],[4,6]]

// **Explanation:**

// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no. of elements in first array"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter no. of elements in second array"<<endl;
    int y;
    cin>>y;
    cout<<"enter second array elements"<<endl;
    vector<int>v1(y);
    for(int i=0;i<y;i++)
    {
        cin>>v1[i];
    }
    vector<vector<int>>ans;
    vector<int>sol;
    for(auto s:v)
    {
        if(find(v1.begin(),v1.end(),s)!=v1.end())
        {
         continue;
        }
        else{
            sol.push_back(s);
        }
    }
    ans.push_back(sol);
    sol.clear();
     for(auto s:v1)
    {
        if(find(v.begin(),v.end(),s)!=v.end())
        {
         continue;
        }
        else{
            sol.push_back(s);
        }
    }
    ans.push_back(sol);
    sol.clear();
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
// enter no. of elements in first array
// 3
// enter your elements
// 1 2 3
// enter no. of elements in second array
// 3
// enter second array elements
// 2 4 6
// 1 3 
// 4 6
