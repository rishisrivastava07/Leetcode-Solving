class Solution {
    string lcs(string &s1, string &s2, int len1, int len2, vector<vector<int>> &dp){
        for(int i = 0; i < len1; i++) dp[i][0] = 0;
        for(int j = 0; j < len2; j++) dp[0][j] = 0;

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string ans = "";
        int i = len1, j = len2;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                // UP
                ans += s1[i-1];
                i--;
            }
            else{
                // LEFT
                ans += s2[j-1];
                j--;
            }
        }

        // put the remaining elements in ans
        while(i > 0){
            ans += s1[i-1];
            i--;
        }
        while(j > 0){
            ans += s2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));
        // to calculate the supersequence length = len1 + len2 - len(lcs(str1, str2));
        return lcs(str1, str2, len1, len2, dp);
    }
};