class Solution {
public:
    int sumOfDigits(int n){
        // TC : O(n)
        int result = 0;
        while(n > 0){
            int rem = n % 10;
            result += rem;
            n /= 10;
        }

        return result;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        unordered_map<int, int> mp;

        // TC : O(n*n*n)
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i != j){
                    if(sumOfDigits(nums[i]) == sumOfDigits(nums[j])){
                        result = max(result, nums[i] + nums[j]);
                    }
                }
            }
        }

        return result;

        // TC : O(n * k)
        // SC : O(n)
        for(int i = 0; i < n; i++){
            int sum = sumOfDigits(nums[i]);
            
            if(mp.count(sum) > 0){
                result = max(result, nums[i] + mp[sum]);
            }

            mp[sum] = max(nums[i], mp[sum]);
        }

        return result;
    }
};