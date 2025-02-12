class Solution {
    int findPivot(vector<int>& nums, int st, int en) {
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

    bool binarySearch(vector<int>& nums,int target, int st, int en){
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) st = mid + 1;
            else en = mid - 1;
        }
        return false;
    }

    pair<int, int> removeDuplicates(vector<int> &nums){
        int st = 0;
        int en = nums.size()-1;

        while(st < en && nums[st] == nums[st+1]) st++;
        while(st < en && nums[en] == nums[en-1]) en--;

        return {st, en}; 
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        pair<int, int> idx = removeDuplicates(nums);
        int st = idx.first, en = idx.second;

        int pivotIdx = findPivot(nums, st, en);

        bool left = binarySearch(nums, target, st, pivotIdx-1);
        bool right = binarySearch(nums, target, pivotIdx, en);

        return left or right; 
    }
};