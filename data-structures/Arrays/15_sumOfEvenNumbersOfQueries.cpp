/*
    Company Tags : Indeed
    Leetcode - 985
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Time Complexity - O(N^2) Space Complexity - O(N)
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int idx = queries[i][1];
            nums[idx] = nums[idx] + queries[i][0];

            int sum = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] % 2 == 0) sum += nums[i];
            }
            result.push_back(sum);
        }

        return result;
    }
};

int main(){
    // Driver Code 
    return 0;
}