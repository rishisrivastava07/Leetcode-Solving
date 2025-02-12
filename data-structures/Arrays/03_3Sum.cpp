/*
    Company Tags :  Amazon, Facebook, Google

    LeetCode - 15
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach 1 - Time Complexity - O(N * log N), Space Complexity - O(1)
        int n = nums.size();
        // if the size is less than 3 then return empty array
        if(n < 3) return {};

        // Sort the nums array
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        // Traverse for each nums[i] as first element and apply 2Sum on other two elements
        for(int i = 0; i < n; i++){
            // if the current element is same as previous element then skip the iteration
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            // initialise the st and en pointers
            int st = i + 1;
            int en = n - 1;

            // Apply Binary Searching on it
            while(st < en){
                int target = -nums[i];
                int two_sum = nums[st] + nums[en];

                if(two_sum > target) en--;
                else if(two_sum < target) st++;
                else{
                    ans.push_back({nums[i],nums[st],nums[en]});
                    st++;
                    en--;

                    // Remove Duplicates from the sorted array
                    while(st < en && nums[st] == nums[st-1]) st++;
                    while(st < en && nums[en] == nums[en+1]) en--;
                }
            }
        }
        return ans;
    }
};
 
int main(){
    // Write Driver Code
    return 0;
}