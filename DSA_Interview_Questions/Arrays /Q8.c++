// <aside>
// 💡 **Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n.
//  Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
//  which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// **Example 1:**
// Input: nums = [1,2,2,4]
// Output: [2,3]

// </aside>

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter the no. of elements in your array"<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements"<<endl;
    vector<int>v(n+1);
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    for(int i=1;i<v.size();i++)
    {
        if(mp[i]==2)
        {
            v[0]=i;
        }
        if(mp[i]==0)
        {
            v[1]=i;
        }
    }
    
    cout<<"the repeated and missing elements are"<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<v[i]<<" ";
    }

}
// enter the no. of elements in your array
// 4
// enter the elements
// 1 2 2 4
// the repeated and missing elements are
// 2 3
