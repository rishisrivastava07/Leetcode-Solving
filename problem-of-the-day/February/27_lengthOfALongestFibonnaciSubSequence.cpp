// Approach - 01 - simple recursion
class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp){
        int target = arr[k] - arr[j];
        if(mp.count(target) && mp[target] < j){
            return solve(mp[target], j, arr, mp) + 1;
        }

        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        for(int j = 1; j < n-1; j++){
            for(int k = j + 1; k < n; k++){
                int length = solve(j, k, arr, mp);
                if(length >= 3){
                    result = max(result, length);
                }
            }
        }

        return result;
    }
};

// Approach - 02 - (dp (memoziation))
class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp, vector<vector<int>>& dp){
        int target = arr[k] - arr[j];
        if(dp[j][k] != -1) return dp[j][k];

        if(mp.count(target) && mp[target] < j){
            return dp[j][k] = solve(mp[target], j, arr, mp, dp) + 1;
        }

        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        for(int j = 1; j < n-1; j++){
            for(int k = j + 1; k < n; k++){
                int length = solve(j, k, arr, mp, dp);
                if(length >= 3){
                    result = max(result, length);
                }
            }
        }
        return result;
    }
};

// Approach - 03 dp (tabulation)
class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp, vector<vector<int>>& dp){
        if(dp[j][k] != -1) return dp[j][k];
        int target = arr[k] - arr[j];

        if(mp.count(target) && mp[target] < j){
            return dp[j][k] = solve(mp[target], j, arr, mp, dp) + 1;
        }

        return dp[j][k] = 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        int result = 0;
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int target = arr[k] - arr[j];
                if(mp.count(target) && mp[target] < j){
                    int i = mp[target];
                    dp[j][k] = dp[i][j] + 1;
                }
                
                result = max(result, dp[j][k]);
            }
        }
        return result >= 3 ? result : 0;
    }
};
