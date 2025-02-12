include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int dp[46];
    int solve(int idx){
        if(idx < 0) return 0;
        if(idx == 0) return 1;

        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = solve(idx-1) + solve(idx-2);
    }
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2) return n;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main(){
    // driver code
    return 0;
}