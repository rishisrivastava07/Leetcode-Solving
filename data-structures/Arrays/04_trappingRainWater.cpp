/*
    Company Tags :  Amazon, Facebook, Google

    LeetCode - 42
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int n = height.size();

        // We will maintain the maximum buildings from both sides
        vector<int> leftMaxBuilding(n), rightMaxBuilding(n);
        // initialise the extreme buildings with there original heights
        leftMaxBuilding[0] = height[0];
        rightMaxBuilding[n-1] = height[n-1];

        for(int i = 1; i < n; i++) leftMaxBuilding[i] = max(leftMaxBuilding[i-1], height[i]);
        for(int i = n-2; i >= 0; i--) rightMaxBuilding[i] = max(rightMaxBuilding[i+1], height[i]);

        for(int i = 0; i < n; i++){
            int filledWater = min(leftMaxBuilding[i], rightMaxBuilding[i]) - height[i];
            trappedWater += filledWater;
        }

        return trappedWater;
    }
};

int main(){
    // Write Driver Code
    return 0;
}