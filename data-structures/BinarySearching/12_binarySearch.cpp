class Solution {
    int binarySearch(vector<int>& nums, int target, int st, int en){
        if(st > en) return -1;
        
        int mid = st + (en - st)/2;
        
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return binarySearch(nums, target, st, mid-1);
        return binarySearch(nums, target, mid+1, en);
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, en = n - 1;

        return binarySearch(nums, target, st, en);
    }
};