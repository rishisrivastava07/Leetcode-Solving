/*
    Company Tags : Amazon

    LeetCode - 167
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    // Approach 1 - Time Complexity - O(N * log N), Space Complexity - O(1)
    // Since the nums array is given sorted & apply binary search instead of inner loop

    int n = numbers.size();
    for(int i = 0; i < n; i++){
        int st = i+1, en = n-1;
        while(st <= en){
            int mid = st + (en - st)/2;

            if((numbers[mid] + numbers[i]) == target) return {i+1, mid+1};
            else if((numbers[mid] + numbers[i]) > target) en = mid - 1;
            else st = mid + 1;
        }
    }
    return {-1, -1};

    // Approach - 2 : Time Complexity - O(log N), Space Complexity - O(1)
    // We can directly apply Binary Search on numbers array
    int n = numbers.size();
    int st = 0;
    int en = n-1;

    while(st <= en){
        int mid = st + (en - st)/2;
        int twoSum = numbers[st] + numbers[en];

        if(twoSum == target) return {st+1, en+1};
        else if(twoSum < target) st++;
        else en--;
    }

    return {-1, -1};
}   
int main(){
    // Provide Driver Code before running the code
    return 0;
}