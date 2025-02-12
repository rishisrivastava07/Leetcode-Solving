class Solution {
public:
    int findLeftMost(vector<int>& nums, int target, int n){
        int st = 0, en = n - 1;

        int leftMost = -1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] < target){
                st = mid + 1;
            }
            else if(nums[mid] > target){
                en = mid - 1;
            }
            else{
                leftMost = mid;
                en = mid - 1;
            }
        }
        return leftMost;
    }
    int findRightMost(vector<int>& nums, int target, int n){
        int st = 0, en = n - 1;

        int rightMost = -1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] < target){
                st = mid + 1;
            }
            else if(nums[mid] > target){
                en = mid - 1;
            }
            else{
                rightMost = mid;
                st = mid + 1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int leftMostOcc = findLeftMost(nums, target, n);
        int rightMostOcc = findRightMost(nums, target, n);

        return {leftMostOcc, rightMostOcc};
    }
};