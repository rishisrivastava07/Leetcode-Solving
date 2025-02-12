/*
    Company Tags : 
    Accolite, Amazon, Microsoft, Infosys, Zoho, Flipkart, 
    Morgan Stanley, FactSet, Hike, ABCO, Wipro, SAP Labs, CarWale

    LeetCode - 1
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Approach - 1 : Time Complexity - O(N^2), Space Complexity - O(1)
    int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
    return {-1, -1};

    // Approach - 2 (Using Map) : Time Complexity - O(N), Space Complexity - O(N)
    int n = nums.size();
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        int remains = target - nums[i];
        if(mp.find(remains) != mp.end()){
            return {mp[remains], i};
        }
        else{
            mp[nums[i]] = i;
        }
    }
    return {-1, -1};
}

int main(){
    
    // provide the driver code
    return 0;
}