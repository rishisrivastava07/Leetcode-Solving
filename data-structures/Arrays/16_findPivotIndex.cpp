/*
    Company tags : Amazon, Adobe, Coupang, Radius
    Leetcode - 724, 1991
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Time Complexity - O(N + N*k), Space Complexity - O(1)
        int n = nums.size();
        
        int leftSum = 0;
        int rightSum = accumulate(begin(nums), end(nums), 0);

        for(int i = 0; i < n; i++){
            int currSum = nums[i];
            rightSum -= currSum;

            if(leftSum == rightSum) return i;
            leftSum += currSum;
        }

        return -1;
    }
};

int main(){
    // Driver Code  
    return 0;
}