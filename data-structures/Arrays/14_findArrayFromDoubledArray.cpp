/*
    Company Tags : Google, Amazon, HCL, IBM, Accenture
    Leetcode - 2007
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n % 2 != 0) return {};

        sort(begin(changed), end(changed));
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[changed[i]]++;
        }

        vector<int> result;
        for(int& num : changed){
            int twice = 2 * num;

            if(mp[num] == 0) continue;
            if(mp.find(twice) == mp.end() || mp[twice] == 0) return {};
        
            result.push_back(num);
            mp[num]--;
            mp[twice]--;
        }

        return result;
    }
};

int main(){
    // driver code
    return 0;
}