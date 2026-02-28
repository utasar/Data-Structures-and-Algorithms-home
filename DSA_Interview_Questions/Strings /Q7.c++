// Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// **Example 1:**

// **Input:** s = "ab#c", t = "ad#c"

// **Output:** true

// **Explanation:**

// Both s and t become "ac".

#include<bits/stdc++.h>
using namespace std;
string checking(string &s)
{
    stack<char>st;
    string s1="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='#')
        {
            if(!st.empty())
            {
                st.pop();
            }
        }
    else
    st.push(s[i]);
    }
  while(!st.empty())
  {
    s1=st.top()+s1;
    st.pop();
  }
  return s1;
    
}
int main()
{
    string s,t;
    cin>>s>>t;
  
     string s1="";
    string check =checking(s);
    string check2 =checking(t);
    if(check==check2)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}
