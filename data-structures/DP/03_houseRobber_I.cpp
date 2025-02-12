include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int n, int idx){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = solve(nums, n, idx+2) + nums[idx];
        int notPick = solve(nums, n, idx+1);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // Memoization Method
        memset(dp, -1, sizeof(dp));
        return solve(nums, n, 0);

        // Bottom Up Approach - Tabulation
        if(n <= 1) return nums[0];
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++){
            int pick = dp[i-2] + nums[i-1];
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }

        return dp[n];


        // Space Optimization
        int prevPrev = 0, prev = nums[0];

        for(int i = 2; i <= n; i++){
            int steal = prevPrev + nums[i-1];
            int skip = prev;

            prevPrev = prev;
            prev = max(steal, skip);
        }

        return prev;
    }
};


int main(){
    // driver code
    return 0;
}