class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int en = nums.size()-1;

        while(st < en){
            int mid = st + (en - st)/2;
            if(nums[mid] > nums[en]){
                // pivot lies in right side
                st = mid + 1;
            } else{
                en = mid;
            }
        } 
        return nums[en];
    }
};