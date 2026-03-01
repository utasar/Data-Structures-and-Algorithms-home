// Question 11
// We define a harmonious array as an array where the difference between its maximum value
// and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence
// among all its possible subsequences.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5

// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements"<<endl;
    vector<int>v(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;

    }
    cout<<"the final solution is"<<endl;
    int maxLength=0;
    for(auto s:mp)
    {
        int key=s.first;
        if(mp.find(key+1)!=end(mp))
        {
            maxLength=max(maxLength,s.second+mp[key+1]);
        }
    }
 cout<<"max length is "<<maxLength;
}

// enter the no. of elements
// 8
// enter the elements
// 1 3 2 2 5 2 3 7
// the final solution is
// max length is 5
