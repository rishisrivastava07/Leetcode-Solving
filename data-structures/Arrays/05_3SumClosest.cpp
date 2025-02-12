/*
    Company Tags :  Meta(Facebook), Amazon, Microsoft, Oracle

    LeetCode - 16
*/

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 1000000;
        sort(begin(nums), end(nums));

        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - closestSum)) closestSum = sum;
                else if(sum < target) j++;
                else k--;
            }
        }
        return closestSum;
    }
};

int main(){
    // Write driver code 
    return 0;
}