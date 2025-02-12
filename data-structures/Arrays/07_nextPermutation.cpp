/*
    Company Names - Amazon, FactSet, Hike, Amazon, MakeMyTrip, Qualcomm, Infosys, Microsoft, Google, Salesforce, Flipkart
    Leetcode - 31
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Time Complexity - O(N) Space Complexity - O(1)
        int n = nums.size();

        int swappedIdx1 = -1;
        // checking the first number from where we can go to next permutations
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                // store the index of i-1 which we need to swap at end with next greater element
                swappedIdx1 = i-1;
                break;
            }
        }

        // If the swappedIdx1 is still -1 that means there is no possible element present after that permutations so skip else do these part
        if(swappedIdx1 != -1){
            int swappedIdx2 = swappedIdx1;
            // find the next greater element in nums array which is just greater than the nums[swappedIdx1] value and store its index value
            for(int i = n-1; i >= swappedIdx1+1; i--){
                if(nums[i] > nums[swappedIdx1]){
                    swappedIdx2 = i;
                    break;
                }
            }

            // Swap both elements
            swap(nums[swappedIdx1], nums[swappedIdx2]);
        }

        // Now reverse the right side subarray from swappedIdx+1 to end to finally obtain the next permutations
        reverse(begin(nums)+swappedIdx1 + 1, end(nums));
    }
};


int main(){
    // Driver Code here
    return 0;
}