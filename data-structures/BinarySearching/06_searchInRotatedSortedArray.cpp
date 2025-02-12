class Solution {
    int findPivot(vector<int>& nums) {
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
        return en;
    }

    int binarySearch(vector<int>& nums,int target, int st, int en){
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) st = mid + 1;
            else en = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, en = n-1;
        int pivotIdx = findPivot(nums);

        int left = binarySearch(nums, target, st, pivotIdx-1);
        int right = binarySearch(nums, target, pivotIdx, en);

        if(left != -1) return left;
        if(right != -1) return right;

        return -1;
    }
};