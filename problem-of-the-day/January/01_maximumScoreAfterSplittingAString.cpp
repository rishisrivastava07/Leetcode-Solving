class Solution {
public:
    // Approach - 01 -> TC - O(N^2) SC - O(1)
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
    // Approach - 02 -> TC - O(N) SC - O(1)
    int maxScore(string s) {
        int n = s.size();
        int result = INT_MIN;

        int totalOnes = 0;              
        for(char ch: s){
            if(ch == '1') totalOnes++;
        }

        int countZeros = 0;
        int countLeftOnes = 0;
        int countOnes = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '0') countZeros++;
            else countLeftOnes++;

            countOnes = totalOnes - countLeftOnes;

            result = max(result, countZeros + countOnes);
        }
        return result;
    }

    // Approach - 03 -> TC - O(N) SC - O(1) ---> In one pass
    int maxScore(string s) {
        int n = s.size();
        int totalOnes = 0;

        int result = INT_MIN, countZeros = 0, countOnes = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '0') countZeros++;
            else countOnes++;

            result = max(result, countZeros - countOnes);
        }
        // if last character is '1' in the string then
        if(s[n-1] == '1') countOnes++;
        
        return result + countOnes;
    }
};