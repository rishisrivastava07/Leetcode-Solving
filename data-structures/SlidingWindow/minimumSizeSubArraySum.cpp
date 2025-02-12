#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        // take two variables for storing sum and minimal length
        int variableSum = 0;
        int minLength = n+1;  

        // Similar to basic sliding window pattern traverse until j < n
        while(j < n){
            // store the index j value to variable sum
            variableSum += nums[j];

            // run the loop until we get the smaller value than target by increasing index i
            while(variableSum >= target){
                // and also calculating simultanously the minimal length of subarray
                minLength = min(minLength, (j-i+1));
                variableSum -= nums[i];
                i++;
            }

            j++;
        }

        // if we cannot find any subarray sum whose is equal or greater than target we simply return 0 
        // else value of minimal length of subarray
        return minLength == n+1 ? 0 : minLength;
    }
};

int main(){
    /*
        Example 1:

        Input: target = 7, nums = [2,3,1,2,4,3]
        Output: 2
        Explanation: The subarray [4,3] has the minimal length under the problem constraint.
        Example 2:

        Input: target = 4, nums = [1,4,4]
        Output: 1
        Example 3:

        Input: target = 11, nums = [1,1,1,1,1,1,1,1]
        Output: 0
        

        Constraints:

        1 <= target <= 109
        1 <= nums.length <= 105
        1 <= nums[i] <= 104
    */    
    return 0;
}