// Question 12
// You have a long flowerbed in which some of the plots are planted, and some are not.
// However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
// and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

#include<bits/stdc++.h>
using namespace std;
bool can_Planted(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    
    for (int i = 0; i < size && n > 0; i++) {
        if (flowerbed[i] == 0) {
            // Check if the current plot can have a flower planted
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);
            
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;  // Plant a flower here
                n--;  // Decrease the count of flowers to plant
            }
        }
    }
    
    return n == 0;  // Return true if all flowers are planted, else false
}

int main()
{
    cout<<"enter the no. of flower beds"<<endl;
    int n;
    cin>>n;
    cout<<"enter the flower beds data"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter no. of plants that needs to be planted"<<endl;
    int y;
    cin>>y;
    bool ans =can_Planted(v,y);
    cout <<ans;
}
// enter the no. of flower beds
// 5
// enter the flower beds data
// 1 0 0 0 1
// enter no. of plants that needs to be planted
// 1
// 1
