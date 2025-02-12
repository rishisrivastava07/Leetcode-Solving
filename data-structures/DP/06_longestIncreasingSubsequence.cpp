#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int sz, int prevIdx, int currIdx){
        if(currIdx >= sz) return 0;

        if(prevIdx != -1 && dp[currIdx][prevIdx] != -1) return dp[currIdx][prevIdx];

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[currIdx]) 
            take = 1 + solve(nums, sz, currIdx, currIdx+1);
        int skip = solve(nums, sz, prevIdx, currIdx+1);

        if(prevIdx != -1) dp[currIdx][prevIdx] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        // Top Down Approach - Memoization Method
        dp = vector<vector<int>> (n , vector<int> (n, -1));
        // solve(nums_array, size, prev_idx, curr_idx)
        return solve(nums, n, -1, 0);
    
        // Bottom Up Approach - Tabulation Method
        vector<int> dp(n, 1);
        for(int currIdx = 0; currIdx < n; currIdx++){
            for(int prevIdx = 0; prevIdx < currIdx; prevIdx++){
                if(nums[prevIdx] < nums[currIdx]) 
                    dp[currIdx] = max(1 + dp[prevIdx], dp[currIdx]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    // Driver code
    return 0;
}