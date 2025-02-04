class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];

        int i = 1;
        int currResult = nums[0];
        while(i < n){
            if(nums[i-1] < nums[i]){
                currResult += nums[i];
                result = max(result, currResult);
            } else {
                currResult = nums[i];
                result = max(result, currResult);
            }
            i++;

        }

        return result;

    }
};