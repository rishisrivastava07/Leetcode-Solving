#include<bits/stdc++.h>
using namespace std;
 
// Approach 01 - TC : O(n^2) & SC : O(1)
int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    for(int i = 0; i < n; i++){
        int mask = 0;
        for(int j = i; j < n; j++){
            if((mask & nums[j]) != 0) break;
            mask |= nums[j];
            result = max(result, j-i+1);
        }
    }
    return result;
}

// Approach 02 - Sliding Window - TC : O(2*N) & SC : O(1) 
int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();

    int i = 0, j = 0;
    int mask = 0;

    int result = 1;

    while(j < n){
        while((mask & nums[j]) != 0){
            mask ^= nums[i];
            i++;
        }

        result = max(result, j - i + 1);
        mask |= nums[j];
        j++;
    }

    return result;
}

int main(){
    // driver code 
    return 0;
}