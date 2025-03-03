class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n, 0);

        int countLess = 0, countEqual = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) countLess++;
            if(nums[i] == pivot) countEqual++; 
        }

        // set the pointers
        int i = 0, j = countLess, k = countLess + countEqual;

        for(int ptr = 0; ptr < n; ptr++){
            if(nums[ptr] < pivot) result[i++] = nums[ptr];
            else if(nums[ptr] == pivot) result[j++] = nums[ptr];
            else result[k++] = nums[ptr];
        }

        return result;
    }
};