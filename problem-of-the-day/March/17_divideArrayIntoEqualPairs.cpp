#include<bits/stdc++.h>
using namespace std;
 
// Approach - 1
bool divideArray(vector<int>& nums) {
    int n = nums.size();
    if(n % 2 != 0) return false;
    unordered_map<int, int> freq;
    for(int &it : nums) freq[it] += 1;
    for(auto& it : freq) 
        if(it.second % 2 != 0) return false;

    return true;
}


int main(){
    // driver code
    return 0;
}