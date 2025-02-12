include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int n;
    long long dp[1000001][2];
    long long solve(vector<int>& nums, int idx, bool isEven){
        // Base case
        if(idx >= n) return 0;
        if(dp[idx][isEven] != -1) return dp[idx][isEven];
        // DP case
        long long skip = solve(nums, idx+1, isEven);
        int value = (isEven == true) ? nums[idx] : -nums[idx];

        long long take = value + solve(nums, idx+1, !isEven);

        return dp[idx][isEven] = max(take, skip); 
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        // memset(dp, -1, sizeof(dp));

        // return solve(nums, 0, true);
        vector<vector<long>> dp(n+1, vector<long>(2, 0));      
        for(int i = 1; i <= n; i++){
            // for even 0
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
            // for odd 1
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};
int main(){
    // driver code
    return 0;
}