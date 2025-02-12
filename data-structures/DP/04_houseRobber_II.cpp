include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n+1, -1);
        dp[0] = 0;
        int prevPrev = -1, prev = 0;
        
        // Case 1 - Steal 0th Position House
        for(int i = 1; i < n; i++){
            int steal = nums[i-1] + (i-2 >= 0 ? prevPrev : 0);
            int skip = prev;

            prevPrev = prev;
            prev = max(skip, steal);
        }

        int result1 = prev;
        dp.clear();
        
        // Case 2 - Skip 0th Position House
        dp[0] = 0;
        dp[1] = 0;
        prevPrev = 0, prev = 0;

        for(int i = 2; i <= n; i++){
            int steal = nums[i-1] + prevPrev;
            int skip = prev;

            prevPrev = prev;
            prev = max(skip, steal);
        }

        int result2 = prev;

        return max(result1, result2);
    }
};

int main(){
    // driver code
    return 0;
}