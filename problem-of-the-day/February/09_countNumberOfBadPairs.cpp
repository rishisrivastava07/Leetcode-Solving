class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairs = 0;

        for(int i = 0; i < n; i++){
            nums[i] -= i;
        }

        unordered_map<int, int> mp;
        mp[nums[0]] = 1;

        for(int i = 1; i < n; i++){
            int totalNumsBefore_i = i;
            badPairs += (totalNumsBefore_i - mp[nums[i]]);
            mp[nums[i]] += 1;
        }

        return badPairs;
    }
};