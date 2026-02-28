// <aside>
// 💡 **Question 4**

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// **Example 1:**

// **Input:** s = "Let's take LeetCode contest"

// **Output:** "s'teL ekat edoCteeL tsetnoc"

// </aside>

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    string ans = "";
    string word = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
        {
            word=s[i]+word;
        }
        else
        {
            ans=ans+" "+word;
            word="";
        }
    }
    ans=ans+" "+ word;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
}

// Let's take LeetCode contest
//  s'teL ekat edoCteeL tsetnoc
