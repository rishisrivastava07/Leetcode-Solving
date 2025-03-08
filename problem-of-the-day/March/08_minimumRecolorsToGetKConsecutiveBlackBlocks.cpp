// Approach - 01 (Brute Force)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = INT_MAX;

        for(int i = 0; i <= n-k; i++){
            int count = 0;
            for(int j = i; j-i+1 <= k; j++){
                if(blocks[j] == 'W') count++;
            }

            result = min(result, count);
        }

        return result;
    }
};

// Approach - 02 : Sliding Window
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = k;

        int i = 0, j = 0;
        int count = 0;
        while(j < n){
            if(blocks[j] == 'W') count++;

            if(j-i+1 == k){
                result = min(result, count);
                if(blocks[i] == 'W'){
                    count--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
};