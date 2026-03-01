// <aside>
// 💡 **Question 3**
// Given a 2D integer array matrix, return *the **transpose** of* matrix.

// The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// **Example 1:**

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[1,4,7],[2,5,8],[3,6,9]]

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter no. of rows and col"<<endl;
    int n;
    cin>>n;
    cout<<"enter your elements"<<endl;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
  
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[j][i]<<" ";
        }
        cout<<endl;

    }

}

// enter no. of rows and col
// 3
// enter your elements
// 1 2 3 4 5 6 7 8 9
// 1 4 7 
// 2 5 8
// 3 6 9
