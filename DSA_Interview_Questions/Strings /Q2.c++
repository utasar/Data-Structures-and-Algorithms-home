// <aside>
// 💡 **Question 2**

// Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

// A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

// **Example 1:**

// **Input:** num = "69"

// **Output:**

// true

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter your string"<<endl;
    string s;
    cin>>s;
    unordered_map<char,char>mp={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    string s1="";
    for(int i=0;i<s.size();i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            cout<<false;
            break;
        }
        else{
           s1=mp[s[i]]+s1;
        }
    }
    if(s.compare(s1)==0)
    cout<<"true";
    else
    cout<<"false";
}
