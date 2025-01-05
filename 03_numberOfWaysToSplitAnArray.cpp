class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // calculate the sum of the nums array
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
    
        long long leftSum = 0;
        long long rightSum = 0;
        int splits = 0;
        
        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];
            rightSum = totalSum - leftSum;

            if(leftSum >= rightSum) splits++;
        }

        return splits;
    }
};