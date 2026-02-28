// Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// **Example 1:**

// **Input:** num1 = "11", num2 = "123"

// **Output:**

// "134"

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter string 1"<<endl;
    string num1;
    cout<<"enter string 2"<<endl;
    string num2;
    int i = num1.length()-1,j = num2.length()-1;
    int carry = 0;
    string s="";
    while(i&&j)
    {
        int sum = (num1[i] - '0') + (num2[j] -'0') +carry;
        if(sum>10)
        {
            carry = sum/10;
            sum=sum%10;
        }
        s=to_string(sum)+s;
        i--;
        j--;
    }
}
