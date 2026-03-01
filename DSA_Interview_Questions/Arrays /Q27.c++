// <aside>
// 💡 **Question 27**
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

// Given the integer n, return *the number of **complete rows** of the staircase you will build*.

// **Example 1:**

// []()

// ![v2.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4bd91cfa-d2b1-47b3-8197-a72e8dcfff4b/v2.jpg)

// **Input:** n = 5

// **Output:** 2

// **Explanation:** Because the 3rd row is incomplete, we return 2.

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no. of coins"<<endl;
    int n;
    cin>>n;
    int levels=0;
    int i=1;
    while(n>=i)
    {
      n=n-i;
      i=i+1;
      levels++;
    }
cout<<levels;
}
// enter no. of coins
// 6
// 3
