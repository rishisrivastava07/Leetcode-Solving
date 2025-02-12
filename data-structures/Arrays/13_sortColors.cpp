/*
    Company Tags : Adobe, Amazon, Hike, MakeMyTrip, MAQ Software, Microsoft, Morgan Stanley,
    Ola Cabs, OYO Rooms, Paytm, Qualcomm, Samsung, SAP Labs, Snapdeal, Walmart, Yatra.com, Flipkart
    LeetCode - 1329
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach - 01 : Time Complexity - O(N+N) Space Complexity - O(1)
        // Linear Approach
        int countRed = 0, countWhite = 0, countBlue = 0;

        for(int& color : nums){
            if(color == 0) countRed++;
            if(color == 1) countWhite++;
            if(color == 2) countBlue++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(countRed > 0) {
                nums[i] = 0;
                countRed--;
            } else if(countWhite > 0) { 
                nums[i] = 1;
                countWhite--;
            } else if(countBlue > 0) { 
                nums[i] = 2;
                countBlue--;
            }
        }

        // Approach - 02 : Time Complexity - O(N) Space Complexity - O(1)
        // Two Pointer Approach
        int i = 0, j = 0, n = nums.size();

        while(j < n){
            if(nums[j] == 0){
                nums[j] = nums[i];
                nums[i] = 0;

                i++;
                j++;
            }
            else if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                nums[j] = nums[n-1];
                nums[n-1] = 2;

                n--;
            }
        }
    }
};

int main(){
    // Driver Code  
    return 0;
}