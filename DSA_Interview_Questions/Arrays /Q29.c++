// <aside>
// 💡 **Question 29**

// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// *Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

// **Example 1:**

// **Input:** nums = [2,5,1,3,4,7], n = 3

// **Output:** [2,3,5,4,1,7]

// **Explanation:** Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no. of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter the element from where you want to divide"<<endl;
    int y;
    cin>>y;
    cout<<"the final output is"<<endl;
    int i=0;
    int j=y;
    int k=0;
    vector<int>ans;
    while(i<y&&j<n)
    {
      ans.push_back(v[i]);
      ans.push_back(v[j]);
      i++;
      j++;
    }
   for(int m=0;m<n;m++)
   {
    cout<<ans[m]<<" ";
   }

}
// enter no. of elements
// 6
// enter your elements
// 2 5 1 3 4 7
// enter the element from where you want to divide
// 3
// the final output 
// 2 3 5 4 1 7
