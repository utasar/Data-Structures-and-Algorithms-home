// <aside>
// 💡 **Question 5**

// Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.

// The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

// **Example 1:**

// **Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2

// **Output:** 2

// **Explanation:**

// For arr1[0]=4 we have:

// |4-10|=6 > d=2

// |4-9|=5 > d=2

// |4-1|=3 > d=2

// |4-8|=4 > d=2

// For arr1[1]=5 we have:

// |5-10|=5 > d=2

// |5-9|=4 > d=2

// |5-1|=4 > d=2

// |5-8|=3 > d=2

// For arr1[2]=8 we have:

// **|8-10|=2 <= d=2**

// **|8-9|=1 <= d=2**

// |8-1|=7 > d=2

// **|8-8|=0 <= d=2**

// </aside>

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>one;
    for(int i=0;i<one.size();i++)
    {
     cin>>one[i];
    }
    cout<<"enter no. of elements"<<endl;
    int y;
    cin>>y;
    cout<<"enter your elements"<<endl;
    vector<int>two;
    for(int i=0;i<two.size();i++)
    {
        cin>>two[i];
    }
    cout<<"enter value of d"<<endl;
    int d;
    cin>>d;
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    int l1=0;
    int l2=0;
    int count=0;
    while(l1<one.size()&&l2<two.size())
    {
        if(abs(one[l1]+two[l2])<=d)
        {
        count++;
        if(one[l1]<two[l2])
         l2++;
        }
    }
}
