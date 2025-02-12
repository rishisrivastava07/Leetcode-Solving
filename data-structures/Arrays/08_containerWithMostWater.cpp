/*
    Company Tags  :   Bloomberg, Facebook, Google, Amazon, Adobe
    Leetcode - 11
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Approach 01 - Time Complexity - O(N) using Two Pointer Approach
        // We traverse from start and the end points of given vector heights
        int n = height.size();

        int area = 0;
        int i = 0, j = n-1;

        while(i <= j){
            // Calculate the current area
            int currArea = (j - i) * min(height[i], height[j]);
            // Take the max of current area and area
            area = max(currArea, area);

            // Move pointer according if height[i] < height[j] move forward i pointer
            // else move j pointer backward
            if(height[i] <= height[j])  i++;
            else j--;
        }

        return area;
    }
};

int main(){
    // Driver Code  
    return 0;
}