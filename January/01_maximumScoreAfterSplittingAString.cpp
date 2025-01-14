class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int result = INT_MIN;

        for(int i = 0; i < n-1; i++){
            // 0 to i - count zero's
            int count_0 = 0;
            for(int j = 0; j <= i; j++){
                if(s[j] == '0') count_0++;
            }

            // i+1 to n-1 - count 1's
            int count_1 = 0;
            for(int j = i+1; j < n; j++){
                if(s[j] == '1') count_1++;
            }

            result = max(result, count_0 + count_1);                
        }

        return result;
    }
};