// Question 13
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

#include<bits/stdc++.h>
using namespace std;
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
int max_Product=0;
int max_Product1=0;
sort(v.begin(),v.end());
max_Product=v[n-1]*v[n-2]*v[n-3];
max_Product1=v[0]*v[1]*v[n-1];
cout<<"ans is "<<max(max_Product1,max_Product)<<endl;
}

// enter the no. of elements
// 3
// enter your elements
// 1 2 3
// ans is 6
