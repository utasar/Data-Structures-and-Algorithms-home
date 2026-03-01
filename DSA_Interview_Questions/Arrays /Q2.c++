// <aside>
// 💡 **Q2.** Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// - Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//  The remaining elements of nums are not important as well as the size of nums.
// - Return k.

// **Example :**
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_*,_*]

// **Explanation:** Your function should return k = 2, with the first two elements of nums being 2.
//  It does not matter what you leave beyond the returned k (hence they are underscores)[

// </aside>

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter number of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        v.push_back(y);
    }
    cout<<"enter the value you want to remove"<<endl;
    int val;
    cin>>val;
    vector<int>secondary_array;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=val)
        {
            secondary_array.push_back(v[i]);
        }
    }
    v.resize(secondary_array.size());
     for(int i=0;i<secondary_array.size();i++)
    {
        v[i]=secondary_array[i];
        cout<<v[i]<<" ";
    }
}
// enter number of elements
// 4
// enter your elements
// 3 2 2 3
// enter the value you want to remove
// 3
// 2 2 
