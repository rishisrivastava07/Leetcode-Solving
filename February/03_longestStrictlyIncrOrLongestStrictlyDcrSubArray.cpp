class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        int icr = 1, dcr = 1;

        int i = 1;
        while(i < n){
            if(nums[i-1] < nums[i]){
                icr++;
                dcr = 1;

                result = max(icr, result);
            }
            else if(nums[i-1] > nums[i]){
                dcr++;
                icr = 1;

                result = max(result, dcr);
            } else {
                icr = 1;
                dcr = 1;
            }

            i++;
        }

        return result;
    }
};